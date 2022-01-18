#include "demosaic.h"

struct neighbors {
  int top, bottom, left, right, top_left, top_right, bottom_left, bottom_right;
};

typedef struct neighbors Struct;

Struct get_neighbors_pixels(int index, int width) {
  Struct neighbors;

  neighbors.top = index - width;
  neighbors.bottom = index + width;
  neighbors.left = index - 1;
  neighbors.right = index + 1;
  neighbors.top_left = neighbors.top - 1;
  neighbors.top_right = neighbors.top + 1;
  neighbors.bottom_left = neighbors.bottom - 1;
  neighbors.bottom_right = neighbors.bottom + 1;

  return neighbors;
}

void demosaic(const std::vector<unsigned char>& bayer, const int& width,
              const int& height, std::vector<unsigned char>& rgb) {
  rgb.resize(width * height * 3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int curr_index = (width * i + j);
      int channel = 0;

      Struct neighbors = get_neighbors_pixels(curr_index, width);

      // even row, even column = g
      // even row, odd column = b
      // odd row, even column = r
      // odd row, odd column = g
      int r = 0;
      int g = 0;
      int b = 0;
      if (i % 2 == 0) {
        if (j % 2 == 0) {
          // sitting on G.
          // L/R is B
          // U/D is R
          // Diags are also G
          channel = 1;
        } else {
          // Sitting on B
          // L/R is G
          // U/D is G
          // Diag is R
          channel = 2;
        }
      } else {
        if (j % 2 == 0) {
          // R
          channel = 0;
        } else {
          // G
          channel = 1;
        }
      }
    }
  }
}
