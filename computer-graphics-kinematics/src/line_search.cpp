#include "line_search.h"

#include <iostream>

double line_search(const std::function<double(const Eigen::VectorXd &)> &f,
                   const std::function<void(Eigen::VectorXd &)> &proj_z,
                   const Eigen::VectorXd &z, const Eigen::VectorXd &dz,
                   const double max_step) {
    /////////////////////////////////////////////////////////////////////////////
    // Replace with your code
    double h = max_step;
    Eigen::VectorXd new_point = z - h * dz;

    double optimal_scalar = f(z);
    double current_point_scalar = f(new_point);
    while (current_point_scalar > optimal_scalar) {
        h = h / 2;
        new_point = z - h * dz;
        proj_z(new_point);
        current_point_scalar = f(new_point);
    }
    return h;
    /////////////////////////////////////////////////////////////////////////////
}
