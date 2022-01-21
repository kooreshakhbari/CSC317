#include "viewing_ray.h"

#include <Eigen/Core>
void viewing_ray(const Camera& camera, const int i, const int j,
                 const int width, const int height, Ray& ray) {
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  ray.origin = camera.e;

  // U
  ray.direction[0] = camera.width * ((i + 0.5) / width) - camera.width / 2;
  // V
  ray.direction[1] = camera.height * ((j + 0.5) / height) - camera.height / 2;
  ray.direction[2] = -1 * camera.d;

  Eigen::Matrix3d camera_transformation_matrix;
  camera_transformation_matrix << camera.u, camera.v, camera.w;

  Eigen::Vector3d dot_product = camera_transformation_matrix * ray.direction;

  ray.direction = dot_product;
}
