#include "insert_triangle_into_box.h"
using namespace std;

void insert_triangle_into_box(const Eigen::RowVector3d& a,
                              const Eigen::RowVector3d& b,
                              const Eigen::RowVector3d& c, BoundingBox& B) {
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  B.min_corner[0] = min(a[0], b[0], c[0]);
  B.min_corner[1] = min(a[1], b[1], c[1]);
  B.min_corner[2] = min(a[2], b[2], c[2]);

  B.max_corner[0] = max(a[0], b[0], c[0]);
  B.max_corner[1] = max(a[1], b[1], c[1]);
  B.max_corner[2] = max(a[2], b[2], c[2]);
}
