#include "Triangle.h"
#include "Ray.h"
#include <Eigen/Geometry>

bool Triangle::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
	// First, find the normal of the plane that the three corners create.
	// Obtain the three points, and create two vectors from them.
	Eigen::Vector3d p1 = std::get<0>(corners);
	Eigen::Vector3d p2 = std::get<1>(corners);
	Eigen::Vector3d p3 = std::get<2>(corners);

	Eigen::Vector3d v1 = p2 - p1;
	Eigen::Vector3d v2 = p3 - p1;

	// Now, find the normal of the plane.
	Eigen::Vector3d planeNormal = v1.cross(v2);

	// Next, find out if the ray intersects this plane.
	// This part uses code from Plane.cpp.
	double denom = ray.direction.dot(planeNormal);
	if (denom != 0.0) {
		// Triangle Normal
		Eigen::Vector3d triangleNormal = v1.cross(v2) / (v1.cross(v2)).norm();
		// Next, we want to see if the t-value is at least min_t.
		double final_t = ((p3 - ray.origin).dot(planeNormal)) / denom;
		if (final_t >= min_t) {
			// Finally, check if the area of the triangle is equal to the total area of the
			// three smaller triangles created with the intersection-point.
			Eigen::Vector3d intersecion = ray.origin + (final_t * ray.direction);
			Eigen::Vector3d v3 = intersecion - p1;

			// Use barycentric coordinates to find if the point is in the triangle:
			double a_val = (v1.cross(v3)).dot(planeNormal) / (planeNormal.dot(planeNormal));
			double b_val = (v3.cross(v2)).dot(planeNormal) / (planeNormal.dot(planeNormal));
			double y_val = 1 - a_val - b_val;

			t = final_t;
			n = triangleNormal;
			return (0 <= a_val && a_val <= 1
					&& 0 <= b_val && b_val <= 1
					&& 0 <= y_val && y_val <= 1);

		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
  ////////////////////////////////////////////////////////////////////////////
}


