#include "kinematics_jacobian.h"

#include <iostream>

#include "transformed_tips.h"

void kinematics_jacobian(const Skeleton& skeleton, const Eigen::VectorXi& b,
                         Eigen::MatrixXd& J) {
    /////////////////////////////////////////////////////////////////////////////
    // Replace with your code
    J = Eigen::MatrixXd::Zero(b.size() * 3, skeleton.size() * 3);
    Eigen::VectorXd trans_tips = transformed_tips(skeleton, b);
    double da = 1e-7;
    for (int bb = 0; bb < b.size(); bb++) {
        for (int i = 0; i < skeleton.size(); i++) {
            Skeleton duplicate = skeleton;
            for (int j = 0; j < 3; j++) {
                duplicate[i].xzx[j] += da;
                Eigen::VectorXd dup_trans_tips = transformed_tips(duplicate, b);
                // Change in tip positions
                Eigen::VectorXd dx = dup_trans_tips - trans_tips;
                Eigen::VectorXd dx_da = dx / da;
                for (int k = 0; k < J.rows(); k++) {
                    J(bb * 3 + k, i * 3 + j) = dx_da[k];
                }
            }
        }
    }

    /////////////////////////////////////////////////////////////////////////////
}
