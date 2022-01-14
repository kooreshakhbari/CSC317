#include "write_ppm.h"

#include <cassert>
#include <fstream>
#include <iostream>
using namespace std;
// P3
// 3 4
// 255
// #the P3 means colors are in ascii, then 3 columns and 4 rows, then 255 for
// max color, then RGB triplets
bool write_ppm(const std::string& filename,
               const std::vector<unsigned char>& data, const int width,
               const int height, const int num_channels) {
  assert((num_channels == 3 || num_channels == 1) &&
         ".ppm only supports RGB or grayscale images");
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  ofstream file;
  // Write the header
  file.open(filename);
  file << "P3" << endl;
  file << width << " " << height << endl;
  file << 255 << endl;

  for (int i = 0; i < data.size() - 3; i += 3) {
    file << (unsigned int)data[i] << " " << (unsigned int)data[i + 1] << " "
         << (unsigned int)data[i + 2] << endl;
  }

  file.close();
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
