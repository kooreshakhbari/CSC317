#include "per_vertex_normals.h"
#include "triangle_area_normal.h"

void per_vertex_normals(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  Eigen::MatrixXd & N)
{
  N = Eigen::MatrixXd::Zero(V.rows(),3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  ////////////////////////////////////////////////////////////////////////////

  // Go through each vertex and check which faces are connected to it
  // Find all associated normals
  for (int v=0; v < V.rows(); v++) {

    Eigen::RowVector3d n (0,0,0);

    for (int f=0; f < F.rows(); f++) {

      if (F(f, 0) != v && F(f, 1) != v && F(f, 2) != v) {
        continue;
      }

      Eigen::RowVector3d a = V.row(F(f, 0));
      Eigen::RowVector3d b = V.row(F(f, 1));
      Eigen::RowVector3d c = V.row(F(f, 2));
      n += triangle_area_normal(a, b, c);

    }

    N.row(v) << n.normalized();
  }
}
