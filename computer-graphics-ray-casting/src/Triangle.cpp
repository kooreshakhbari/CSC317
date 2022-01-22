#include "Triangle.h"

#include <Eigen/Dense>
#include <iostream>

#include "Ray.h"
using namespace std;
bool Triangle::intersect(const Ray& ray, const double min_t, double& t,
                         Eigen::Vector3d& n) const {
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  Eigen::Vector3d t1;
  Eigen::Vector3d t2;
  Eigen::Vector3d n1;

  t1 = get<1>(this->corners) - get<0>(this->corners);
  t2 = get<2>(this->corners) - get<0>(this->corners);

  Eigen::Matrix3d left_matrix;
  left_matrix << t1, t2, -1 * ray.direction;

  if (left_matrix.determinant() == 0) return false;

  Eigen::Vector3d answer =
      left_matrix.colPivHouseholderQr().solve(ray.origin - get<0>(corners));

  double alpha = answer[0];
  double beta = answer[1];
  double potential_t = answer[2];

  if (alpha < 0 || beta < 0 || alpha + beta > 1) {
    return false;
  }

  if (potential_t < min_t) {
    return false;
  }

  t = potential_t;

  n = t1.cross(t2);

  return true;
  ////////////////////////////////////////////////////////////////////////////
}
