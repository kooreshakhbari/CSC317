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

  t1 = b.transpose() - a.transpose();
  t2 = c.transpose() - a.transpose();
  // Formula from slides
  Eigen::RowVector3d normal = t1.cross(t2) / t1.cross(t2).norm();
  

  return normal;
}
