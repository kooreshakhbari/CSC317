#include "PointLight.h"

#include <math.h>
void PointLight::direction(const Eigen::Vector3d& q, Eigen::Vector3d& d,
                           double& max_t) const {
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  ////////////////////////////////////////////////////////////////////////////

  d = (this->p - q);

  max_t = sqrt(pow(d[0], 2) + pow(d[1], 2) + pow(d[2], 2));

  d = d.normalized();
}
