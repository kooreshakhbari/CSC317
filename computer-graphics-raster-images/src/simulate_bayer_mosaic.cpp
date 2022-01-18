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
  // Pattern is gbgb
  //            brbr
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int curr_index = (width * i + j);
      int channel = 0;
      // Get the color based on row and colmn being odd or even
      // even row, even column = b
      // even row, odd column = g
      // odd row, even column = g
      // odd row, odd column = r

      if (i % 2 == 0) {
        if (j % 2 == 0) {
          channel = 2;
        } else {
          channel = 1;
        }
      } else {
        if (j % 2 == 0) {
          channel = 1;
        } else {
          channel = 0;
        }
      }

      bayer[curr_index] = rgb[3 * curr_index + channel];
    }
  }
}
