#include "ray_intersect_triangle_mesh_brute_force.h"

#include <iostream>

#include "ray_intersect_triangle.h"
using namespace std;
bool ray_intersect_triangle_mesh_brute_force(
    const Ray& ray, const Eigen::MatrixXd& V, const Eigen::MatrixXi& F,
    const double min_t, const double max_t, double& hit_t, int& hit_f) {
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  // cout << F.rows() << endl;
  // cout << V.rows() << endl;
  double curr_t;
  hit_t = std::numeric_limits<double>::infinity();
  for (int i = 0; i < F.rows(); i++) {
    Eigen::RowVector3d v1 = V.row(F(i, 0));
    Eigen::RowVector3d v2 = V.row(F(i, 1));
    Eigen::RowVector3d v3 = V.row(F(i, 2));

    bool intersect =
        ray_intersect_triangle(ray, v1, v2, v3, min_t, max_t, curr_t);

    if (intersect == true && curr_t < hit_t) {
      hit_t = curr_t;
      hit_f = i;
    }
  }

  if (hit_t != std::numeric_limits<double>::infinity()) {
    return true;
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
