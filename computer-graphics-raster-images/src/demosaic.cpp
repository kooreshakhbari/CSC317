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
      int count_red = 0;
      int count_green = 0;
      int count_blue = 0;
      if (i % 2 == 0) {
        if (j % 2 == 0) {
          // sitting on G.
          // L/R is B
          // U/D is R
          // Diags are also G

          g = bayer[curr_index];
          count_green = 1;

          // Check L and R bounds for blue
          if (j > 0) {
            b += bayer[neighbors.left];
            count_blue += 1;
          }

          if (j < width - 1) {
            b += bayer[neighbors.right];
            count_blue += 1;
          }

          // Check U and D for R

          if (i > 0) {
            r += bayer[neighbors.top];
            count_red += 1;
          }

          if (i < height - 1) {
            r += bayer[neighbors.bottom];
            count_red += 1;
          }

        } else {
          // Sitting on B
          // L/R is G
          // U/D is G
          // Diag is R

          b = bayer[curr_index];
          count_blue = 1;

          // Check L and R bounds for G
          if (j > 0) {
            g += bayer[neighbors.left];
            count_green += 1;
          }

          if (j < width - 1) {
            g += bayer[neighbors.right];
            count_green += 1;
          }

          // Check U and D for G

          if (i > 0) {
            g += bayer[neighbors.top];
            count_green += 1;
          }

          if (i < height - 1) {
            g += bayer[neighbors.bottom];
            count_green += 1;
          }

          // Check diag for R

          if (i > 0 && j > 0) {
            r += bayer[neighbors.top_left];
            count_red += 1;
          }

          if (i > 0 && j < width - 1) {
            r += bayer[neighbors.top_right];
            count_red += 1;
          }

          if (i < height - 1 && j > 0) {
            r += bayer[neighbors.bottom_left];
            count_red += 1;
          }
          if (i < height - 1 && j < width - 1) {
            r += bayer[neighbors.bottom_right];
            count_red += 1;
          }
        }
      } else {
        if (j % 2 == 0) {
          // R
          // L/R G
          // U/D G
          // Diag is B

          r = bayer[curr_index];
          count_red = 1;

          // Check L and R bounds for G
          if (j > 0) {
            g += bayer[neighbors.left];
            count_green += 1;
          }

          if (j < width - 1) {
            g += bayer[neighbors.right];
            count_green += 1;
          }

          // Check U and D for G

          if (i > 0) {
            g += bayer[neighbors.top];
            count_green += 1;
          }

          if (i < height - 1) {
            g += bayer[neighbors.bottom];
            count_green += 1;
          }

          // Check diag for B

          if (i > 0 && j > 0) {
            b += bayer[neighbors.top_left];
            count_blue += 1;
          }

          if (i > 0 && j < width - 1) {
            b += bayer[neighbors.top_right];
            count_blue += 1;
          }

          if (i < height - 1 && j > 0) {
            b += bayer[neighbors.bottom_left];
            count_blue += 1;
          }
          if (i < height - 1 && j < width - 1) {
            b += bayer[neighbors.bottom_right];
            count_blue += 1;
          }

        } else {
          // G
          // L/R R
          // U/D B
          // Diag R

          g = bayer[curr_index];
          count_green = 1;

          // Check L and R bounds for r
          if (j > 0) {
            r += bayer[neighbors.left];
            count_red += 1;
          }

          if (j < width - 1) {
            r += bayer[neighbors.right];
            count_red += 1;
          }

          // Check U and D for B

          if (i > 0) {
            b += bayer[neighbors.top];
            count_blue += 1;
          }

          if (i < height - 1) {
            b += bayer[neighbors.bottom];
            count_blue += 1;
          }

          // Check diag for B

          if (i > 0 && j > 0) {
            r += bayer[neighbors.top_left];
            count_red += 1;
          }

          if (i > 0 && j < width - 1) {
            r += bayer[neighbors.top_right];
            count_red += 1;
          }

          if (i < height - 1 && j > 0) {
            r += bayer[neighbors.bottom_left];
            count_red += 1;
          }
          if (i < height - 1 && j < width - 1) {
            r += bayer[neighbors.bottom_right];
            count_red += 1;
          }
        }
      }

      if (count_red > 0) {
        r = r / count_red;
      }

      if (count_green > 0) {
        g = g / count_green;
      }

      if (count_blue > 0) {
        b = b / count_blue;
      }

      rgb[3 * curr_index] = r;
      rgb[3 * curr_index + 1] = g;
      rgb[3 * curr_index + 2] = b;
    }
  }
}
