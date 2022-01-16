#include "hue_shift.h"

#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void hue_shift(const std::vector<unsigned char> &rgb, const int width,
               const int height, const double shift,
               std::vector<unsigned char> &shifted) {
  shifted.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  for (int i = 0; i < rgb.size(); i += 3) {
    // According to readme on github for sensitive computations convert rgb to
    // between 0, 1
    double r = rgb[i] / 255.0;
    double g = rgb[i + 1] / 255.0;
    double b = rgb[i + 2] / 255.0;
    double h = 0;
    double s = 0;
    double v = 0;

    rgb_to_hsv(r, g, b, h, s, v);

    // Get the h

    if (h + shift >= 360) {
      h = h + shift - 360;
    } else {
      h += shift;
    }
    hsv_to_rgb(h, s, v, r, g, b);

    shifted[i] = (unsigned char)(r * 255.0);
    shifted[i + 1] = (unsigned char)(g * 255.0);
    shifted[i + 2] = (unsigned char)(b * 255.0);
  }
}
