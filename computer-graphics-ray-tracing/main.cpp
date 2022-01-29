#include <Eigen/Core>
#include <chrono>
#include <functional>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

#include "Camera.h"
#include "Light.h"
#include "Object.h"
#include "raycolor.h"
#include "read_json.h"
#include "viewing_ray.h"
#include "write_ppm.h"
using namespace std::chrono;

int main(int argc, char* argv[]) {
  auto start = high_resolution_clock::now();
  Camera camera;
  std::vector<std::shared_ptr<Object> > objects;
  std::vector<std::shared_ptr<Light> > lights;
  // Read a camera and scene description from given .json file
  read_json(argc <= 1 ? "../data/creative.json" : argv[1], camera,
            objects, lights);

  int width = 640;
  int height = 360;
  std::vector<unsigned char> rgb_image(3 * width * height);
  // For each pixel (i,j)
  for (unsigned i = 0; i < height; ++i) {
    for (unsigned j = 0; j < width; ++j) {
      // Set background color
      Eigen::Vector3d rgb(0, 0, 0);

      // Compute viewing ray
      Ray ray;
      viewing_ray(camera, i, j, width, height, ray);

      // Shoot ray and collect color
      raycolor(ray, 1.0, objects, lights, 0, rgb);

      // Write double precision color into image
      auto clamp = [](double s) { return std::max(std::min(s, 1.0), 0.0); };
      rgb_image[0 + 3 * (j + width * i)] = 255.0 * clamp(rgb(0));
      rgb_image[1 + 3 * (j + width * i)] = 255.0 * clamp(rgb(1));
      rgb_image[2 + 3 * (j + width * i)] = 255.0 * clamp(rgb(2));
    }
  }

  write_ppm("rgb.ppm", rgb_image, width, height, 3);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<seconds>(stop - start);
  std::cout << duration.count() << std::endl;
}
