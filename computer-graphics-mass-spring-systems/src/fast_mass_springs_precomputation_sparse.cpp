#include "fast_mass_springs_precomputation_sparse.h"

#include <vector>

#include "signed_incidence_matrix_sparse.h"

bool fast_mass_springs_precomputation_sparse(
    const Eigen::MatrixXd& V, const Eigen::MatrixXi& E, const double k,
    const Eigen::VectorXd& m, const Eigen::VectorXi& b, const double delta_t,
    Eigen::VectorXd& r, Eigen::SparseMatrix<double>& M,
    Eigen::SparseMatrix<double>& A, Eigen::SparseMatrix<double>& C,
    Eigen::SimplicialLLT<Eigen::SparseMatrix<double> >& prefactorization) {
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  std::vector<Eigen::Triplet<double> > ijv;
  const int n = V.rows();
  double w = 1e10;
  // for (int i = 0; i < n; i++) ijv.emplace_back(i, i, 1);

  // Create r
  r.resize(E.rows());
  for (int i = 0; i < E.rows(); i++) {
    int index_0 = E(i, 0);
    int index_1 = E(i, 1);
    r[i] = (V.row(index_0) - V.row(index_1)).norm();
  }

  // Create M
  M.resize(V.rows(), V.rows());
  for (int i = 0; i < M.rows(); i++) {
    ijv.emplace_back(i, i, m[i]);
  }
  M.setFromTriplets(ijv.begin(), ijv.end());

  // Create A
  signed_incidence_matrix_sparse(V.rows(), E, A);

  // Create C
  C.resize(b.rows(), V.rows());
  ijv.clear();
  for (int i = 0; i < b.rows(); i++) {
    ijv.emplace_back(i, b[i], 1);
  }
  C.setFromTriplets(ijv.begin(), ijv.end());

  // Create Q
  Eigen::SparseMatrix<double> Q(n, n);
  // Q.setFromTriplets(ijv.begin(), ijv.end());
  Q = k * A.transpose() * A + M / pow(delta_t, 2) + w * C.transpose() * C;

  /////////////////////////////////////////////////////////////////////////////
  prefactorization.compute(Q);
  return prefactorization.info() != Eigen::NumericalIssue;
}
