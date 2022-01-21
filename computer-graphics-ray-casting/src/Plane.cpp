#include "Plane.h"

#include "Ray.h"

bool Plane::intersect(const Ray& ray, const double min_t, double& t,
                      Eigen::Vector3d& n) const {
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:

  if (this->normal.dot(ray.direction) == 0) {
    return false;
  }

  t = (this->normal.dot(this->point) - this->normal.dot(ray.origin)) /
      (this->normal.dot(ray.direction));

  if (t < min_t) {
    return false;
  }

  n = this->normal.normalized();
  return true;
  ////////////////////////////////////////////////////////////////////////////
}
