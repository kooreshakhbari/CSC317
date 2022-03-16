#include "end_effectors_objective_and_gradient.h"

#include <iostream>

#include "copy_skeleton_at.h"
#include "kinematics_jacobian.h"
#include "transformed_tips.h"

void end_effectors_objective_and_gradient(
    const Skeleton &skeleton, const Eigen::VectorXi &b,
    const Eigen::VectorXd &xb0,
    std::function<double(const Eigen::VectorXd &)> &f,
    std::function<Eigen::VectorXd(const Eigen::VectorXd &)> &grad_f,
    std::function<void(Eigen::VectorXd &)> &proj_z) {
    /////////////////////////////////////////////////////////////////////////////
    // Replace with your code
    // Formulas in handout of lab
    f = [&](const Eigen::VectorXd &A) -> double {
        Eigen::VectorXd trans_tips =
            transformed_tips(copy_skeleton_at(skeleton, A), b);

        double val = (trans_tips - xb0).squaredNorm();

        return val;
    };

    grad_f = [&](const Eigen::VectorXd &A) -> Eigen::VectorXd {
        Eigen::VectorXd trans_tips =
            transformed_tips(copy_skeleton_at(skeleton, A), b);

        Eigen::VectorXd E(b.size() * 3);

        Eigen::MatrixXd J;
        kinematics_jacobian(copy_skeleton_at(skeleton, A), b, J);

        E = (trans_tips - xb0) * 2;

        return J.transpose() * E;
    };
    proj_z = [&](Eigen::VectorXd &A) {
        assert(skeleton.size() * 3 == A.size());

        for (int i = 0; i < skeleton.size(); i++) {
            Bone bone = skeleton[i];
            A[i * 3] =
                std::max(bone.xzx_min[0], std::min(A[i * 3], bone.xzx_max[0]));
            A[i * 3 + 1] = std::max(bone.xzx_min[1],
                                    std::min(A[i * 3 + 1], bone.xzx_max[1]));
            A[i * 3 + 2] = std::max(bone.xzx_min[2],
                                    std::min(A[i * 3 + 2], bone.xzx_max[2]));
        }
    };
    /////////////////////////////////////////////////////////////////////////////
}
