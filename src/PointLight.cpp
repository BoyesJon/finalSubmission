#include "PointLight.h"

void PointLight::direction(
  const Eigen::Vector3d & q, Eigen::Vector3d & d, double & max_t) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
	// Find the direction from point q to light point d. Then normalize the result.
	d = p - q;
	max_t = 1;
  ////////////////////////////////////////////////////////////////////////////


}
