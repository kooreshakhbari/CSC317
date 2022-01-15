#include "rgb_to_gray.h"

#include <iostream>

using namespace std;

void rgb_to_gray(const std::vector<unsigned char>& rgb, const int width,
                 const int height, std::vector<unsigned char>& gray) {
  gray.resize(height * width);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  int j = 0;
  for (int i = 0; i < rgb.size(); i += 3) {
    float sum = rgb[i] + rgb[i + 1] + rgb[i + 2];
    float average = sum / 3;
    gray[j] = (unsigned char)average;
    j++;
  }
}
