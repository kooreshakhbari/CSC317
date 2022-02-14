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
       0, 1, 2, 3, // Left
       4, 5, 6, 7, // Right
       2, 3, 6, 7, // Front
       0, 1, 4, 5, // Back
       1, 3, 5, 7; // Top
       
       

  
  UV.resize(14,2);

  UV << 0, 1, // 0
        0, 2, // 1
        1, 0, // 2
        2, 0, // 3
        1, 1, // 4
        2, 1, // 5
        1, 2, // 6
        2, 2, // 7
        1, 3, // 8
        2, 3, // 9
        3, 1, // 10
        3, 2, // 11
        4, 1, // 12
        4, 2; // 13



  UV *= 0.25;

  UF.resize(6,4);

  UF << 2, 3, 4, 5, // White Bot
        4, 5, 6, 7, // Green L
        10, 11, 12, 13, // Orange R
        5, 10, 7, 11, // Blue F
        0, 1, 4, 6, // Red B
        6, 8, 7, 9; // Yellow T 

  
  NV.resize(6,3);

  NV << 0, 0, -1, // Bottom WHITE 0
        1, 0, 0, // Left GREEN 4 
        -1, 0, 0, // Right ORANGE 5
        0, 1, 0, // Front BLUE 1
        0, -1, 0, // Back RED 2
        0, 0, 1; // Top YELLOW 3


  NF.resize(6,4);

  NF << 0, 0, 0, 0, // Bottom WHITE 
        4, 4, 4, 4, // Left GREEN
        5, 5, 5, 5, // Right ORANGE
        1, 1, 1, 1, // Front BLUE
        2, 2, 2, 2, // Back RED
        3, 3, 3, 3; // Top YELLOW
        
        
        


}
