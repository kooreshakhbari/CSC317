#include "viewing_ray.h"

#include <iostream>

using namespace std;
#include <Eigen/Core>
void viewing_ray(const Camera& camera, const int i, const int j,
                 const int width, const int height, Ray& ray) {
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  double u;
  double v;
  double w;
  ray.origin = camera.e;
  // U
  u = camera.width * ((j + 0.5) / width) - camera.width / 2;
  // V
  v = camera.height * ((i + 0.5) / height) - camera.height / 2;
  // W
  w = camera.d;

  ray.direction[0] = u * camera.u[0];
  ray.direction[1] = -1 * v * camera.v[1];
  ray.direction[2] = -1 * w * camera.w[2];
}
