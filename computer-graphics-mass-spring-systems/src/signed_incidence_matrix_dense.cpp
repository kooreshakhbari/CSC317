#include "signed_incidence_matrix_dense.h"

void signed_incidence_matrix_dense(const int n, const Eigen::MatrixXi& E,
                                   Eigen::MatrixXd& A) {
  //////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  A = Eigen::MatrixXd::Zero(E.rows(), n);
  //////////////////////////////////////////////////////////////////////////////

  for (int i = 0; i < E.rows(); i++) {
    for (int j = 0; j < E.cols(); j++) {
      if (i == E(i, 0)) {
        A(i, E(i, 0)) = 1;
      } else if (j == E(i, 1)) {
        A(i, E(i, 1)) = -1;
      }
    }
  }
}
