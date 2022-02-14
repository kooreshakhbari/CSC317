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

  F << 0, 4, 5, 1, // Bottom
       2, 0, 1, 3, // Left
       6, 7, 5, 4, // Right
       7, 3, 1, 5, // Front
       2, 6, 4, 0, // Back
       2, 3, 7, 6; // Top
       
       

  
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

  // The index order matter you need to walk the edges
  UF << 2, 3, 5, 4, // White Bot
        4, 5, 7, 6, // Green L
        10, 11, 13, 12, // Orange R
        5, 10, 11, 7, // Blue F
        0, 1, 6, 4, // Red B
        6, 8, 9, 7; // Yellow T 

  
  NV.resize(6,3);

  NV << 0, -1, 0, // Bottom WHITE 0
        -1, 0, 0, // Left GREEN 1 
        1, 0, 0, // Right ORANGE 2
        0, 0, 1, // Front BLUE 3
        0, 0, -1, // Back RED 4
        0, 1, 0; // Top YELLOW 5


  NF.resize(6,4);

  NF << 0, 0, 0, 0, // Bottom WHITE 
        1, 1, 1, 1, // Left GREEN
        2, 2, 2, 2, // Right ORANGE
        3, 3, 3, 3, // Front BLUE
        4, 4, 4, 4, // Back RED
        5, 5, 5, 5; // Top YELLOW
        
        
        


}
