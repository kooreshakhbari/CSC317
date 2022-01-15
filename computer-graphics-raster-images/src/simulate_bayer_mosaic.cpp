#include "simulate_bayer_mosaic.h"

#include <iostream>

using namespace std;
void simulate_bayer_mosaic(const std::vector<unsigned char>& rgb,
                           const int& width, const int& height,
                           std::vector<unsigned char>& bayer) {
  bayer.resize(width * height);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int curr_index = (width * i + j);
      int channel = 0;
      // Get the color based on row and colmn being odd or even
      if (i % 2 == 0) {
        channel = (j % 2);
      } else {
        channel = 1 + (j % 2);
      }

      bayer[curr_index] = rgb[3 * curr_index + channel];
    }
  }
}
