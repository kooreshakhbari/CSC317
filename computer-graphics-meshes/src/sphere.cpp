#include "sphere.h"
#include <iostream>
#include <math.h>
using namespace std;
void sphere(
  const int num_faces_u,
  const int num_faces_v,
  Eigen::MatrixXd & V,
  Eigen::MatrixXi & F,
  Eigen::MatrixXd & UV,
  Eigen::MatrixXi & UF,
  Eigen::MatrixXd & NV,
  Eigen::MatrixXi & NF)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  ////////////////////////////////////////////////////////////////////////////

  int total_u = num_faces_u + 1;
  int total_v = num_faces_v + 1;
  int total_faces= num_faces_u *  num_faces_v;
  int total_vertices = total_u * total_v;

  V.resize(total_vertices, 3);
  F.resize(total_faces, 4);
  UV.resize(total_vertices, 2);
  UF.resize(total_faces, 4);
  NV.resize(total_vertices, 3);
  NF.resize(total_faces, 4);


  for (int u=0; u <= num_faces_u; u++) {
    double theta =  u * (M_PI  / num_faces_u);
    for (int v=0; v <= num_faces_v; v++) {
      double phi = v * (2 * M_PI  / num_faces_v);
      
      // Formula from slides
      double x = cos(phi) * sin(theta);
      double y = sin(phi) * sin(theta);
      double z = cos(theta);
      
      int index = total_v * u + v;

      // V.row(index) << x, z, y;
      V.row(index) << y, z, x;
      // Multiply by -1 to make the default start view like the gif
      V.row(index) *= -1;
      UV.row(index) << (double) v/total_v, (double) u/total_u;
      NV.row(index) = V.row(index).normalized();

      if (u != num_faces_u && v != num_faces_v) {
        index = v + u * num_faces_v;

        // Calculate the indexes
        int index_1 = v + u * total_v;
        int index_2 = v + (u+1) * total_v;
        int index_3 = index_2 + 1;
        int index_4 = index_1 + 1;

        Eigen::Vector4i indices;
        indices << index_1, index_2, index_3, index_4;
        NF.row(index) = indices;
        UF.row(index) = indices;
        // UF.row(index) << index_1, index_2, index_3, index_4;
        F.row(index) = indices;
      }

    }
  }
}
