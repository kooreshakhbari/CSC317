#include "hsv_to_rgb.h"

#include <algorithm>
#include <cmath>
using namespace std;
void hsv_to_rgb(const double h, const double s, const double v, double &r,
                double &g, double &b) {
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  r = 0;
  g = 0;
  b = 0;
  ////////////////////////////////////////////////////////////////////////////
  // Got algo from https://en.wikipedia.org/wiki/HSL_and_HSV#HSV_to_RGB
  double C = s * v;

  double h_prime = h / 60;

  double X = C * (1 - fabs(fmod(h_prime, 2) - 1));

  if (0 <= h_prime && h_prime < 1) {
    r = C;
    g = X;
    b = 0;
  } else if (1 <= h_prime && h_prime < 2) {
    r = X;
    g = C;
    b = 0;
  } else if (2 <= h_prime && h_prime < 3) {
    r = 0;
    g = C;
    b = X;
  } else if (3 <= h_prime && h_prime < 4) {
    r = 0;
    g = X;
    b = C;
  } else if (4 <= h_prime && h_prime < 5) {
    r = X;
    g = 0;
    b = C;
  } else if (5 <= h_prime && h_prime < 6) {
    r = C;
    g = 0;
    b = X;
  }

  double m = v - C;

  r += m;
  g += m;
  b += m;
}
