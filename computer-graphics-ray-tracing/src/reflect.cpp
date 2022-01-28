#include <Eigen/Core>

Eigen::Vector3d reflect(const Eigen::Vector3d& in, const Eigen::Vector3d& n) {
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:

  // Formula is -(I - 2 * n dot n) * in vector
  Eigen::Matrix3d identity_3d;
  identity_3d.setIdentity();

  Eigen::Vector3d reflected;

  // On the slides there is a negative here but for some reason that messes up
  // the picture
  // reflected = -(identity_3d - Eigen::Matrix3d(2 * n * n.transpose())) * in;
  reflected = (identity_3d - Eigen::Matrix3d(2 * n * n.transpose())) * in;
  reflected.normalized();
  return reflected;
  ////////////////////////////////////////////////////////////////////////////
}
