#include "nearest_neighbor_brute_force.h"

#include <limits>  // std::numeric_limits<double>::infinity();

void nearest_neighbor_brute_force(const Eigen::MatrixXd& points,
                                  const Eigen::RowVector3d& query, int& I,
                                  double& sqrD) {
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:

  auto best_distance = std::numeric_limits<double>::infinity();

  for (int i = 0; i < points.rows(); i++) {
    auto distance = (points.row(i) - query).squaredNorm();

    if (distance < best_distance) {
      best_distance = distance;
      I = i;
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
