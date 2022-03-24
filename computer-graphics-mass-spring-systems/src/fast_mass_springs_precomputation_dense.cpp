#include "fast_mass_springs_precomputation_dense.h"

#include <Eigen/Dense>

#include "signed_incidence_matrix_dense.h"

bool fast_mass_springs_precomputation_dense(
    const Eigen::MatrixXd& V, const Eigen::MatrixXi& E, const double k,
    const Eigen::VectorXd& m, const Eigen::VectorXi& b, const double delta_t,
    Eigen::VectorXd& r, Eigen::MatrixXd& M, Eigen::MatrixXd& A,
    Eigen::MatrixXd& C, Eigen::LLT<Eigen::MatrixXd>& prefactorization) {
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  Eigen::MatrixXd Q = Eigen::MatrixXd::Identity(V.rows(), V.rows());
  /////////////////////////////////////////////////////////////////////////////
  double w = 1e10;
  // Create r
  r.resize(E.rows());
  for (int i = 0; i < E.rows(); i++) {
    int index_0 = E(i, 0);
    int index_1 = E(i, 1);
    r[i] = (V.row(index_0) - V.row(index_1)).norm();
  }

  // Create M
  M = Eigen::MatrixXd::Zero(V.rows(), V.rows());
  for (int i = 0; i < M.rows(); i++) {
    M(i, i) = m[i];
  }

  // Create A
  signed_incidence_matrix_dense(V.rows(), E, A);

  // Create C #b by #V selection matrix
  C = Eigen::MatrixXd::Zero(b.rows(), V.rows());
  for (int i = 0; i < b.rows(); i++) {
    C(i, b[i]) = 1;
  }

  Q = k * A.transpose() * A + M / pow(delta_t, 2) + w * C.transpose() * C;

  prefactorization.compute(Q);
  return prefactorization.info() != Eigen::NumericalIssue;
}
