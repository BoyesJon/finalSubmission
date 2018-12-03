#include <Eigen/Core>

Eigen::Vector3d reflect(const Eigen::Vector3d & in, const Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  Eigen::Vector3d reflectedRay = in - (2 * (in.dot(n)))*n;
  return reflectedRay;
  ////////////////////////////////////////////////////////////////////////////
}
