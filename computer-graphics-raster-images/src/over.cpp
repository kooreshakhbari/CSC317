#include "over.h"

void over(const std::vector<unsigned char>& A,
          const std::vector<unsigned char>& B, const int& width,
          const int& height, std::vector<unsigned char>& C) {
  C.resize(A.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  // Got the algorithm from https://en.wikipedia.org/wiki/Alpha_compositing
  for (int i = 0; i < width * height * 4; i += 4) {
    double alpha_A = A[i + 3] / 255.0;
    double alpha_B = B[i + 3] / 255.0;
    double alpha_o = alpha_A + alpha_B * (1 - alpha_A);
    C[i + 3] = (unsigned char)alpha_o * 255.0;
    for (int channel = 0; channel < 3; channel++) {
      double c_A = A[i + channel];
      double c_B = B[i + channel];
      double c_o = (c_A * alpha_A + c_B * alpha_B * (1 - alpha_A)) / alpha_o;
      C[i + channel] = (unsigned char)c_o;
    }
  }
}
