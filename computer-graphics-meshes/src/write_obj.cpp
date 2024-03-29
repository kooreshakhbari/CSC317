#include "write_obj.h"
#include <fstream>
#include <cassert>
#include <iostream>
using namespace std;
bool write_obj(
  const std::string & filename,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & UV,
  const Eigen::MatrixXi & UF,
  const Eigen::MatrixXd & NV,
  const Eigen::MatrixXi & NF)
{
  assert((F.size() == 0 || F.cols() == 3 || F.cols() == 4) && "F must have 3 or 4 columns");
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  ////////////////////////////////////////////////////////////////////////////
  ofstream file;
  file.open(filename);

  // First write the vertices

  for (int i=0; i < V.rows(); i++) {
    file << "v " << V(i, 0) << " " << V(i, 1) << " " << V(i, 2) << endl;
  }

  // Do VT (texture cords)
  for (int i=0; i < UV.rows(); i++) {
    file << "vt " << UV(i, 0) << " " << UV(i, 1) << endl;
  }

  // Normal vectors
  for (int i=0; i < NV.rows(); i++) {
    file << "vn " << NV(i, 0) << " " << NV(i, 1) << " " << NV(i, 2) << endl;
  }

  // Faces
  for (int i =0; i< F.rows(); i++) {
    file << "f ";
    for (int j=0; j < F.cols(); j++) {
      file << F(i, j)+1 << "/" << UF(i, j)+1 << "/" << NF(i, j)+1 << " ";
    }
    file << endl;

  }
  file.close();

  return true;
}
