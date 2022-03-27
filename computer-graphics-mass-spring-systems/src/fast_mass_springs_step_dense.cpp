#include "fast_mass_springs_step_dense.h"

#include <igl/matlab_format.h>

void fast_mass_springs_step_dense(
    const Eigen::MatrixXd& V, const Eigen::MatrixXi& E, const double k,
    const Eigen::VectorXi& b, const double delta_t, const Eigen::MatrixXd& fext,
    const Eigen::VectorXd& r, const Eigen::MatrixXd& M,
    const Eigen::MatrixXd& A, const Eigen::MatrixXd& C,
    const Eigen::LLT<Eigen::MatrixXd>& prefactorization,
    const Eigen::MatrixXd& Uprev, const Eigen::MatrixXd& Ucur,
    Eigen::MatrixXd& Unext) {
    //////////////////////////////////////////////////////////////////////////////
    // Replace with your code

    // This leads to a straightforward "local-global" iterative algorithm:
    // Step 1 (local): Given current values of  determine  for each spring.
    // Step 2 (global): Given all  vectors, find positions  that minimize
    // quadratic energy $\tilde{E}$. Step 3: if "not satisfied", go to Step 1.

    Eigen::MatrixXd d;
    Eigen::MatrixXd y;
    double w = 1e10;
    y = ((M * (2 * Ucur - Uprev)) / pow(delta_t, 2)) + fext;
    d.resize(E.rows(), 3);
    Unext = Ucur;
    for (int iter = 0; iter < 50; iter++) {
        Eigen::MatrixXd l;

        // Calc dij
        for (int i = 0; i < E.rows(); i++) {
            d.row(i) = (Unext.row(E(i, 0)) - Unext.row(E(i, 1))).normalized();
            d.row(i) *= r[i];
        }

        // From lab handout
        l = k * A.transpose() * d + y + w * C.transpose() * C * V;
        Unext = prefactorization.solve(l);
    }
    //////////////////////////////////////////////////////////////////////////////
}
