#ifndef RECTPRISM_H
#define RECTPRISM_H

#include "RectPrism.h"
#include "Object.h"
#include <Eigen/Core>

class RectPrism : public Object
{
  public:
    Eigen::Vector3d minPoint;
	Eigen::Vector3d maxPoint;
  public:
    // Intersect rectangular prism with ray.
    //
    // Inputs:
    //   Ray  ray to intersect with
    //   min_t  minimum parametric distance to consider
    // Outputs:
    //   t  first intersection at ray.origin + t * ray.direction
    //   n  surface normal at point of intersection
    // Returns iff there a first intersection is found.
    bool intersect(
      const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const;
};

#endif
