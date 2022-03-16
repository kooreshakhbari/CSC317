#include "kinematics_jacobian.h"

#include <iostream>
using namespace std;
#include "transformed_tips.h"

void kinematics_jacobian(const Skeleton& skeleton, const Eigen::VectorXi& b,
                         Eigen::MatrixXd& J) {
    /////////////////////////////////////////////////////////////////////////////
    // Replace with your code
    J = Eigen::MatrixXd::Zero(b.size() * 3, skeleton.size() * 3);
    Eigen::VectorXd trans_tips = transformed_tips(skeleton, b);
    double da = 1e-7;
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < skeleton.size(); j++) {
            Skeleton duplicate = skeleton;
            for (int k = 0; k < 3; k++) {
                duplicate[j].xzx[k] += da;
                Eigen::VectorXd dup_trans_tips = transformed_tips(duplicate, b);

                // Tip of ith bone
                Eigen::Vector3d dup_trans_tips_row;
                Eigen::Vector3d trans_tips_row;
                trans_tips_row[0] = trans_tips(3 * i);
                trans_tips_row[1] = trans_tips(3 * i + 1);
                trans_tips_row[2] = trans_tips(3 * i + 2);

                dup_trans_tips_row[0] = dup_trans_tips(3 * i);
                dup_trans_tips_row[1] = dup_trans_tips(3 * i + 1);
                dup_trans_tips_row[2] = dup_trans_tips(3 * i + 2);
                // Change in tip positions
                Eigen::Vector3d dx = dup_trans_tips_row - trans_tips_row;
                Eigen::Vector3d dx_da = dx / da;
                for (int z = 0; z < 3; z++) {
                    J(i * 3 + z, j * 3 + k) = dx_da(z);
                }
            }
        }
    }

    /////////////////////////////////////////////////////////////////////////////
}
