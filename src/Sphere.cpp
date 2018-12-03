#include "Sphere.h"
#include "Ray.h"
#include <Eigen/Geometry>

bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
	// Defining variables to solve for the quadratic equaation
	double quad_a = (ray.direction.dot(ray.direction));
	double quad_b = 2 * (ray.direction.dot(ray.origin - center));
	double quad_c = (ray.origin - center).dot((ray.origin - center)) - (radius*radius);
	// Solve for the discriminant
	double discriminant = (quad_b * quad_b) - (4 * quad_a * quad_c);

	// If the discriminant is at least 0, then there is an intersection.
	// Find the intersection, and check if the resulting minimum
	// t-value is at least min_t.
	if (discriminant > 0.0) {
		// There are 2 possible solutions. Take the minimum of the two.
		// (The minimum t-value is the closer of the two intersections).
		double t1 = (-quad_b + sqrt(discriminant)) / (2 * quad_a);
		double t2 = (-quad_b - sqrt(discriminant)) / (2 * quad_a);
		double final_t = std::min(t1, t2);
		Eigen::Vector3d intersection = ray.origin + (final_t * ray.direction);
		n = (intersection - center) / radius;
		t = final_t;
		return (t >= min_t);
	}
	else if (discriminant == 0.0) {
		// There is only one solution. Find out if it is at least min_t.
		double final_t = (-quad_b + sqrt(discriminant)) / (2 * quad_a);
		Eigen::Vector3d intersection = ray.origin + (final_t * ray.direction);
		t = final_t;
		return (t >= min_t);
	}
	else {
		// The discriminant is negative, so there is no solution.
		return false;
	}
  
  ////////////////////////////////////////////////////////////////////////////
}

