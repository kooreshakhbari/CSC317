#include "cube.h"

void cube(
  Eigen::MatrixXd & V,
  Eigen::MatrixXi & F,
  Eigen::MatrixXd & UV,
  Eigen::MatrixXi & UF,
  Eigen::MatrixXd & NV,
  Eigen::MatrixXi & NF)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  ////////////////////////////////////////////////////////////////////////////

  ////Hint:
  // Cube 0, 0, 0 bottom left - top right 1, 1, 1
  V.resize(8,3);
  V << 0, 0, 0, // 0
       0, 0, 1, // 1
       0, 1, 0, // 2
       0, 1, 1, // 3
       1, 0, 0, // 4
       1, 0, 1, // 5
       1, 1, 0, // 6
       1, 1, 1; // 7


  
  F.resize(6,4);

  F << 0, 2, 4, 6, // Bottom
       2, 3, 6, 7, // Front
       0, 1, 4, 5, // Back
       1, 3, 5, 7, // Top
       0, 1, 2, 3, // Left
       4, 5, 6, 7; // Right

  
        
  UV.resize(14,2);

  UV << 0, 1, // 1
        0, 2, // 2
        1, 0, // 3
        2, 0, // 4
        1, 1, // 5
        2, 1, // 6
        1, 2, // 7
        2, 2, // 8
        1, 3, // 9
        2, 3, // 10
        3, 1, // 11
        3, 2, // 12
        4, 1, // 13
        4, 2; // 14



  UV *= 0.25;

  UF.resize(6,4);

  UF << 3, 4, 5, 6, // White Bot
        6, 11, 8, 12, // Blue F
        1, 2, 5, 7, // Red B
        7, 9, 10, 8, // Yellow T 
        5, 7, 6, 4, // Green L
        11, 12, 13, 14; // Orange R
  
  NV.resize(6,3);

  NV << -1, 0, 0, // Left face
         1, 0, 0, // Right face
         0, 0, 1, // Top face
         0, 0, -1, // Bottom face
         0, 1, 0, // Front face
         0, -1, 0; // Back face

  

  NF.resize(6,4);

  NF << 3, 3, 3, 3, // Bottom
        4, 4, 4, 4, // Front
        5, 5, 5, 5, // Back
        2, 2, 2, 2, // Top
        0, 0, 0, 0, // Left
        1, 1, 1, 1; // Right
        


}
