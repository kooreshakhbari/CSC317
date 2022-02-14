#include "per_corner_normals.h"
#include "triangle_area_normal.h"
// Hint:
#include "vertex_triangle_adjacency.h"
#include <iostream>
using namespace std;
void per_corner_normals(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const double corner_threshold,
  Eigen::MatrixXd & N)
{
  N = Eigen::MatrixXd::Zero(F.rows()*3,3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  ////////////////////////////////////////////////////////////////////////////

  // Create adjacency list
  std::vector<std::vector<int> > VF;
  vertex_triangle_adjacency(F, V.rows(), VF);

  double threshold = cos(corner_threshold * M_PI / 180.0);

  for (int i = 0; i < F.rows(); i++) {
    Eigen::RowVector3d main_n (0,0,0);
    Eigen::RowVector3d a = V.row(F(i, 0));
    Eigen::RowVector3d b = V.row(F(i, 1));
    Eigen::RowVector3d c = V.row(F(i, 2));
    main_n = triangle_area_normal(a, b, c);

    for (int j = 0; j < F.cols(); j++) {
      Eigen::RowVector3d n (0,0,0);
      int vertex_index = F(i, j);
      // Loop through incident faces of this vertex to calculate their normal
      for (int k=0; k < VF[vertex_index].size(); k++) {
        Eigen::RowVector3d incident_n (0,0,0);
        Eigen::RowVector3d a_comp = V.row(F(VF[vertex_index][k], 0));
        Eigen::RowVector3d b_comp = V.row(F(VF[vertex_index][k], 1));
        Eigen::RowVector3d c_comp = V.row(F(VF[vertex_index][k], 2));
        incident_n = triangle_area_normal(a_comp, b_comp, c_comp);

        // Check if we pass the threshold
        if (abs(main_n.dot(incident_n)) > abs(threshold)) {
          n += incident_n;
        }
      }

      N.row(j + i*3) = n.normalized();





    }
  }

}
