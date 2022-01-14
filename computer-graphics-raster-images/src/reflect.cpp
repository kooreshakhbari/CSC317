#include "reflect.h"

void reflect(const std::vector<unsigned char>& input, const int width,
             const int height, const int num_channels,
             std::vector<unsigned char>& reflected) {
  reflected.resize(width * height * num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i < height; i++) {
    for (int j = width - 1; j >= 0; j--) {
      int z = width - j - 1;
      for (int k = 0; k < num_channels; k++) {
        reflected[k + num_channels * (z + width * i)] =
            input[num_channels * (width * i + j) + k];
      }
    }
  }
}
