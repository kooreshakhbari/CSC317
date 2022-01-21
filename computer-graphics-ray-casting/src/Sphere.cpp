#include "Sphere.h"

#include <algorithm>
using namespace std;
#include "Ray.h"
bool Sphere::intersect(const Ray& ray, const double min_t, double& t,
                       Eigen::Vector3d& n) const {
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  Eigen::Vector3d e = ray.origin - this->center;
  // a, b, c coeffs
  double a = ray.direction.dot(ray.direction);
  double b = 2 * ray.direction.dot(e);
  double c = e.dot(e) - (this->radius * this->radius);

  double discriminant = b * b - 4 * a * c;

  // Imj
  if (discriminant < 0) {
    return false;
  }

  // 1 root and tangent
  if (discriminant == 0) {
    t = (-b) / (2 * a);
    if (t < min_t) {
      return false;
    }
  }

  if (discriminant > 0) {
    double t1 = (-b + discriminant) / (2 * a);
    double t2 = (-b - discriminant) / (2 * a);

    if (t1 < min_t && t2 < min_t) {
      return false;
    }

    if (t1 >= min_t && t2 >= min_t) {
      t = min(t1, t2);
    } else {
      if (min(t1, t2) >= min_t) {
        t = min(t1, t2);
      } else {
        t = max(t1, t2);
      }
    }
  }

  Eigen::Vector3d point_sphere = ray.origin + t * ray.direction;
  n = (point_sphere - this->center).normalized();

  return true;
  ////////////////////////////////////////////////////////////////////////////
}
