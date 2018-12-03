#include "DirectionalLight.h"
#include <limits>

void DirectionalLight::direction(
  const Eigen::Vector3d & q, Eigen::Vector3d & d, double & max_t) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
	// Since the directional light is going to be infinitely far, set d as the light's d.
	// Normalize the d value as well (just for safety, the light's d shoulda already be
	// a unit vector).
	d = -this->d;
	// Because the source is directional, max_t will be infinity.
	max_t = std::numeric_limits<double>::infinity();
  ////////////////////////////////////////////////////////////////////////////
}

