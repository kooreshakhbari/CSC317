#include "box_box_intersect.h"

#include "ray_intersect_box.h"

bool box_box_intersect(const BoundingBox& A, const BoundingBox& B) {
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  // Check for intersection by comparing the corners
  for (int i = 0; i < 3; i++) {
    if (!(A.min_corner[i] <= B.max_corner[i] &&
          A.max_corner[i] >= B.min_corner[i])) {
      return false;
    }
  }
  return true;
  ////////////////////////////////////////////////////////////////////////////
}
