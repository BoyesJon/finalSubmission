#include "Plane.h"
#include "Ray.h"


bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
	// Using the wiki page Line-plane intersection for the equation.
	// First, find out if the denominator value is non-zero.
	// If so, there is an intersection. Evaluate the rest of the equation
	// to find the value for t.
	double denom = ray.direction.dot(normal);
	if (denom != 0.0) {
		double final_t = ((point - ray.origin).dot(normal)) / denom;
		n = normal;
		t = final_t;
		return (t >= min_t);	
	}
	else {
		return false;
	}
  ////////////////////////////////////////////////////////////////////////////
}

