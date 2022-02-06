#include "point_box_squared_distance.h"
using namespace std;
double point_box_squared_distance(const Eigen::RowVector3d& query,
                                  const BoundingBox& box) {
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here
  double ans = 0;
  for (int i = 0; i < 3; i++) {
    // Check to which corner the box is closest to.
    double curr_corner_distance = 0;

    if (query[i] > box.max_corner[i]) {
      curr_corner_distance = pow(query[i] - box.max_corner[i], 2);
    } else if (query[i] < box.min_corner[i]) {
      curr_corner_distance = pow(box.min_corner[i] - query[i], 2);
    } else {
      // You are in the box
      curr_corner_distance = 0;
    }

    ans += curr_corner_distance;
  }

  return ans;
  ////////////////////////////////////////////////////////////////////////////
}
