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
      double para_x = (double) v/total_v;
      double para_y =  (double) u/total_u;

      int index = total_v * u + v;

      V.row(index) << x, y, z;
      UV.row(index) << para_x, para_y;
      NV.row(index) = V.row(index);

      if (u == num_faces_u || v == num_faces_v)
        continue;

      index = v + u * num_faces_v;

      int index_1 = v + u * total_v;
      int index_2 = v + (u+1) * total_v;
      int index_3 = v + (u+1) * total_v + 1;
      int index_4 = v + u * total_v + 1;

      Eigen::Vector4i indices;
      indices << index_1, index_2, index_3, index_4;
      NF.row(index) = indices;
      UF.row(index) = indices;
      F.row(index) = indices;


    }
  }
}
