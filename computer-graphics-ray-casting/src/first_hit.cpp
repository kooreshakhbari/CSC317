#include "first_hit.h"

bool first_hit(const Ray& ray, const double min_t,
               const std::vector<std::shared_ptr<Object> >& objects,
               int& hit_id, double& t, Eigen::Vector3d& n) {
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  bool intersect_found = false;
  bool valid_t_found = false;
  Eigen::Vector3d current_hit_n;
  double current_t;
  for (int i = 0; i < objects.size(); i++) {
    intersect_found = objects[i]->intersect(ray, min_t, t, current_hit_n);

    // Fist intersect found setup init values
    if (intersect_found && !valid_t_found) {
      if (t > min_t) {
        valid_t_found = true;
        current_t = t;
        hit_id = i;
        n = current_hit_n;
      }
    } else if (intersect_found && valid_t_found) {
      if (t < current_t && t > min_t) {
        current_t = t;
        hit_id = i;
        n = current_hit_n;
      }
    }
  }
  return valid_t_found;
  ////////////////////////////////////////////////////////////////////////////
}
