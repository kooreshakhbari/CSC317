#include "triangle_triangle_intersection.h"

#include "ray_intersect_triangle.h"

bool triangle_triangle_intersection(const Eigen::RowVector3d& A0,
                                    const Eigen::RowVector3d& A1,
                                    const Eigen::RowVector3d& A2,
                                    const Eigen::RowVector3d& B0,
                                    const Eigen::RowVector3d& B1,
                                    const Eigen::RowVector3d& B2) {
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:

  // Check if each edge of each triangle intersect with any of the edges of the
  // other triangle
  double t;

  Ray A_edge_1(A0, (A1 - A0));
  if (ray_intersect_triangle(A_edge_1, B0, B1, B2, 0.0, 1.0, t)) {
    return true;
  }

  Ray A_edge_2(A0, (A2 - A0));
  if (ray_intersect_triangle(A_edge_2, B0, B1, B2, 0.0, 1.0, t)) {
    return true;
  }

  Ray A_edge_3(A1, (A2 - A1));
  if (ray_intersect_triangle(A_edge_3, B0, B1, B2, 0.0, 1.0, t)) {
    return true;
  }

  Ray B_edge_1(B0, (B1 - B0));
  if (ray_intersect_triangle(B_edge_1, A0, A1, A2, 0.0, 1.0, t)) {
    return true;
  }

  Ray B_edge_2(B0, (B2 - B0));
  if (ray_intersect_triangle(B_edge_2, A0, A1, A2, 0.0, 1.0, t)) {
    return true;
  }

  Ray B_edge_3(B1, (B2 - B0));
  if (ray_intersect_triangle(B_edge_3, A0, A1, A2, 0.0, 1.0, t)) {
    return true;
  }

  return false;
  ////////////////////////////////////////////////////////////////////////////
}
