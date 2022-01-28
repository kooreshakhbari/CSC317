#include "raycolor.h"

#include "blinn_phong_shading.h"
#include "first_hit.h"
#include "reflect.h"

bool raycolor(const Ray& ray, const double min_t,
              const std::vector<std::shared_ptr<Object> >& objects,
              const std::vector<std::shared_ptr<Light> >& lights,
              const int num_recursive_calls, Eigen::Vector3d& rgb) {
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  double t = 0.0;
  Eigen::Vector3d n;
  int hit_id;
  if (num_recursive_calls > 15) {
    return false;
  }

  if (first_hit(ray, min_t, objects, hit_id, t, n)) {
    // Ray reflected;
    // reflected =
    rgb = blinn_phong_shading(ray, hit_id, t, n, objects, lights);

    Eigen::Vector3d recursive_color;
    Ray reflected_ray;
    reflected_ray.origin = ray.origin + t * ray.direction;
    reflected_ray.direction = reflect(ray.direction, n);
    if (raycolor(ray, min_t, objects, lights, num_recursive_calls + 1,
                 recursive_color)) {
      rgb += recursive_color;
    }
  } else {
    return false;
  }

  rgb = Eigen::Vector3d(0, 0, 0);
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
