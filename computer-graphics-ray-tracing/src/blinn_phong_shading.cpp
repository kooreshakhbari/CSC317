#include "blinn_phong_shading.h"
// Hint:
#include <math.h>

#include <algorithm>

#include "first_hit.h"
using namespace std;
Eigen::Vector3d blinn_phong_shading(
    const Ray& ray, const int& hit_id, const double& t,
    const Eigen::Vector3d& n,
    const std::vector<std::shared_ptr<Object> >& objects,
    const std::vector<std::shared_ptr<Light> >& lights) {
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  // L = ka + kdmax(0, nTray) + ksmax(0, cos(n, h))^p

  // Ray from the point on the surface to the light
  Ray l;
  l.origin = ray.origin + t * ray.direction;

  Eigen::Vector3d v = -(ray.direction).normalized();

  Eigen::Vector3d rgb;

  // Add ambient light
  rgb = 0.1 * objects[hit_id]->material->ka;

  double max_t = 0.0;
  for (std::shared_ptr<Light> light : lights) {
    // All formulas are from the slides.
    int current_hit_id;
    double current_t;
    Eigen::Vector3d current_normal;

    // Create the light vector from point on surface to the light source. Output
    // vec in that direction goes to l.direction
    light->direction(l.origin, l.direction, max_t);

    // Create the half vector according to slide
    Eigen::Vector3d h = (v + l.direction).normalized();

    // If object is not shadow go ahead.
    if (!first_hit(l, 1e-6, objects, current_hit_id, current_t,
                   current_normal) ||
        current_t > max_t) {
      // Lambertian contribution
      rgb += (((objects[hit_id]->material->kd).array() * light->I.array())
                  .matrix() *
              max(0.0, n.dot(l.direction)));

      // Specular contribution
      rgb +=
          (((objects[hit_id]->material->ks).array() * light->I.array())
               .matrix() *
           pow(max(0.0, n.dot(h)), objects[hit_id]->material->phong_exponent));
    }
  }
  return rgb;
  ////////////////////////////////////////////////////////////////////////////
}
