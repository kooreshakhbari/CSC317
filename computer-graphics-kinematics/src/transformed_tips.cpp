#include "transformed_tips.h"

#include "forward_kinematics.h"

Eigen::VectorXd transformed_tips(const Skeleton &skeleton,
                                 const Eigen::VectorXi &b) {
    /////////////////////////////////////////////////////////////////////////////
    // Replace with your code
    std::vector<Eigen::Affine3d, Eigen::aligned_allocator<Eigen::Affine3d>> T;
    forward_kinematics(skeleton, T);

    Eigen::VectorXd ans = Eigen::VectorXd::Zero(3 * b.size());
    for (int i = 0; i < b.size(); i++) {
        int skeleton_index = b[i];

        Eigen::Affine3d transformation = T[skeleton_index];
        Eigen::Vector4d tip;

        tip = T[skeleton_index] * skeleton[skeleton_index].rest_T *
              Eigen::Vector4d(skeleton[skeleton_index].length, 0.0, 0.0, 1.0);

        ans[3 * i] = tip[0];
        ans[3 * i + 1] = tip[1];
        ans[3 * i + 2] = tip[2];
    }

    return ans;
    /////////////////////////////////////////////////////////////////////////////
}
