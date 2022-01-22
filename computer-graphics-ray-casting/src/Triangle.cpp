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

  // Create the two vector
  t1 = get<1>(this->corners) - get<0>(this->corners);
  t2 = get<2>(this->corners) - get<0>(this->corners);

  // Make the vector
  Eigen::Matrix3d left_matrix;
  left_matrix << t1, t2, -1 * ray.direction;

  // Check for linear independence
  if (left_matrix.determinant() == 0) return false;

  // Solve the linear system
  Eigen::Vector3d answer =
      left_matrix.colPivHouseholderQr().solve(ray.origin - get<0>(corners));

  // Extract answers
  double alpha = answer[0];
  double beta = answer[1];
  double potential_t = answer[2];

  // Do checks as mentioned in the lec
  if (alpha < 0 || beta < 0 || alpha + beta > 1) {
    return false;
  }

  // Check that you are in the distance
  if (potential_t < min_t) {
    return false;
  }

  t = potential_t;
  // Get the normal vector
  n = t1.cross(t2).normalized();

  return true;
  ////////////////////////////////////////////////////////////////////////////
}
