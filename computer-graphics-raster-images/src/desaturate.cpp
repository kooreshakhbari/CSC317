#include "desaturate.h"

#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(const std::vector<unsigned char> &rgb, const int width,
                const int height, const double factor,
                std::vector<unsigned char> &desaturated) {
  desaturated.resize(rgb.size());
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

    s = s * (1 - factor);

    hsv_to_rgb(h, s, v, r, g, b);

    desaturated[i] = (unsigned char)(r * 255.0);
    desaturated[i + 1] = (unsigned char)(g * 255.0);
    desaturated[i + 2] = (unsigned char)(b * 255.0);
  }
}
