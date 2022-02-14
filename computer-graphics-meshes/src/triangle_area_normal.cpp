#include "triangle_area_normal.h"
#include <Eigen/Geometry>

Eigen::RowVector3d triangle_area_normal(
  const Eigen::RowVector3d & a, 
  const Eigen::RowVector3d & b, 
  const Eigen::RowVector3d & c)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code:
  ////////////////////////////////////////////////////////////////////////////

  Eigen::Vector3d t1;
  Eigen::Vector3d t2;

  t1 = b - a;
  t2 = c - a;

  Eigen::RowVector3d normal = t1.cross(t2) / 2.0;
  

  return normal;
}
