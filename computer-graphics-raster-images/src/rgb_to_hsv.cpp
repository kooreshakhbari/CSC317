#include "rgb_to_hsv.h"

#include <algorithm>
#include <cmath>

using namespace std;
void rgb_to_hsv(const double r, const double g, const double b, double &h,
                double &s, double &v) {
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  h = 0;
  s = 0;
  v = 0;
  ////////////////////////////////////////////////////////////////////////////
  double M = max({r, g, b});
  double m = min({r, g, b});
  double c = M - m;

  if (M == r) {
    h = fmod((g - b) / c, 6);
  } else if (M == g) {
    h = (b - r) / c + 2;
  } else if (M == b) {
    h = (r - g) / c + 4;
  } else {
    h = 0;
  }

  h = h * 60;

  // scale h to 0, 360

  if (h >= 0) {
    h = fmod(h, 360);
  } else {
    h = fmod(h * -1, 360);
  }

  // Lightness
  v = M;

  // Saturation

  if (v == 0) {
    s = 0;
  } else {
    s = c / v;
  }
}
