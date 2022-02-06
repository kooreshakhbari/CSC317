#include "ray_intersect_triangle.h"

#include <Eigen/Dense>
bool ray_intersect_triangle(const Ray& ray, const Eigen::RowVector3d& A,
                            const Eigen::RowVector3d& B,
                            const Eigen::RowVector3d& C, const double min_t,
                            const double max_t, double& t) {
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:

  // Same code from previous assignment except this->corners is basically A, B,
  // C
  t = 0;

  Eigen::Vector3d t1;
  Eigen::Vector3d t2;

  t1 = B.transpose() - A.transpose();
  t2 = C.transpose() - A.transpose();

  // Make the vector
  Eigen::Matrix3d left_matrix;
  left_matrix << t1, t2, -1 * ray.direction;

  // Check for linear independence
  if (left_matrix.determinant() == 0) return false;

  // Solve the linear system
  Eigen::Vector3d answer =
      left_matrix.colPivHouseholderQr().solve(ray.origin - A.transpose());

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
  return true;
  ////////////////////////////////////////////////////////////////////////////
}
