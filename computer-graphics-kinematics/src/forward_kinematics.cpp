#include "forward_kinematics.h"
#include "euler_angles_to_transform.h"
#include <functional> // std::function

Eigen::Affine3d forward_kinematic_recursive(int index, const Skeleton &skeleton, std::vector<Eigen::Affine3d, Eigen::aligned_allocator<Eigen::Affine3d>> &T)
{
  if (index >= skeleton.size() || index < 0)
  {
    return Eigen::Affine3d::Identity();
  }

  return forward_kinematic_recursive(skeleton[index].parent_index, skeleton, T) * skeleton[index].rest_T * euler_angles_to_transform(skeleton[index].xzx) * skeleton[index].rest_T.inverse();
}

void forward_kinematics(
    const Skeleton &skeleton,
    std::vector<Eigen::Affine3d, Eigen::aligned_allocator<Eigen::Affine3d>> &T)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  T.resize(skeleton.size(), Eigen::Affine3d::Identity());

  for (int i = 0; i < skeleton.size(); i++)
  {
    T[i] = forward_kinematic_recursive(i, skeleton, T);
  }
  /////////////////////////////////////////////////////////////////////////////
}
