#include "rotate.h"

#include <iostream>
using namespace std;

void rotate(const std::vector<unsigned char>& input, const int width,
            const int height, const int num_channels,
            std::vector<unsigned char>& rotated) {
  rotated.resize(height * width * num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i < height; i++) {
    for (int j = width - 1; j >= 0; j--) {
      int z = width - j - 1;
      for (int k = 0; k < num_channels; k++) {
        rotated[k + num_channels * (z * height + i)] =
            input[num_channels * (width * i + j) + k];
      }
    }
  }
}
