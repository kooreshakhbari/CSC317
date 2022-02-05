#include "ray_intersect_box.h"

#include <iostream>
using namespace std;

bool ray_intersect_box(const Ray& ray, const BoundingBox& box,
                       const double min_t, const double max_t) {
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:

  // Code adapted from slides and book page 313

  // First do tx min and max for x axis
  double tx_min;
  double tx_max;

  double a = 1 / ray.direction[0];
  if (a >= 0) {
    tx_min = (a) * (box.min_corner[0] - ray.origin[0]);
    tx_max = (a) * (box.max_corner[0] - ray.origin[0]);

  } else {
    tx_min = (a) * (box.max_corner[0] - ray.origin[0]);
    tx_max = (a) * (box.min_corner[0] - ray.origin[0]);
  }

  // Second do ty min and max for y axis
  double ty_min;
  double ty_max;

  a = 1 / ray.direction[1];
  if (a >= 0) {
    ty_min = (a) * (box.min_corner[1] - ray.origin[1]);
    ty_max = (a) * (box.max_corner[1] - ray.origin[1]);

  } else {
    ty_min = (a) * (box.max_corner[1] - ray.origin[1]);
    ty_max = (a) * (box.min_corner[1] - ray.origin[1]);
  }

  // Third do tz min and max for z axis
  double tz_min;
  double tz_max;

  a = 1 / ray.direction[2];
  if (a >= 0) {
    tz_min = (a) * (box.min_corner[2] - ray.origin[2]);
    tz_max = (a) * (box.max_corner[2] - ray.origin[2]);

  } else {
    tz_min = (a) * (box.max_corner[2] - ray.origin[2]);
    tz_max = (a) * (box.min_corner[2] - ray.origin[2]);
  }

  double min_t_check = max({tx_min, ty_min, tz_min});
  double max_t_check = min({tx_max, ty_max, tz_max});

  if (max_t_check < min_t || min_t_check > max_t || min_t_check > max_t_check) {
    return false;
  }
  return true;
  ////////////////////////////////////////////////////////////////////////////
}
