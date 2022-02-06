#include "AABBTree.h"

// See AABBTree.h for API
bool AABBTree::ray_intersect(const Ray& ray, const double min_t,
                             const double max_t, double& t,
                             std::shared_ptr<Object>& descendant) const {
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  t = 0;
  double left_t;
  double right_t;
  std::shared_ptr<Object> left_objects = this->left;
  std::shared_ptr<Object> right_objects = this->right;
  bool left_intersect =
      this->left->ray_intersect(ray, min_t, max_t, left_t, left_objects);

  bool right_intersect =
      this->left->ray_intersect(ray, min_t, max_t, right_t, right_objects);

  if (left_intersect == true && right_intersect == true) {
    if (left_t < right_t) {
      t = left_t;
      descendant = left_objects;
    } else {
      t = right_t;
      descendant = right_objects;
    }
    return true;
  }
  if (left_intersect == true) {
    t = left_t;
    descendant = left_objects;
    return true;
  }
  if (right_intersect == true) {
    t = right_t;
    descendant = right_objects;
    return true;
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
