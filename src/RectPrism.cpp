#include "RectPrism.h"
#include "Ray.h"
#include <Eigen/Geometry>

bool RectPrism::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
	// Algorithm based on code found on:
	// https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-box-intersection
	double min_t_x = (minPoint.x() - ray.origin.x()) / ray.direction.x();
	double max_t_x = (maxPoint.x() - ray.origin.x()) / ray.direction.x();

	if (min_t_x > max_t_x) {
		std::swap(min_t_x, max_t_x);
	}

	double min_t_y = (minPoint.y() - ray.origin.y()) / ray.direction.y();
	double max_t_y = (maxPoint.y() - ray.origin.y()) / ray.direction.y();

	if (min_t_y > max_t_y) {
		std::swap(min_t_y, max_t_y);
	}

	if ((min_t_x > max_t_y) || (min_t_y > max_t_x)) {
		return false;
	}

	if (min_t_y > min_t_x) {
		min_t_x = min_t_y;
	}
	if (max_t_y < max_t_x) {
		max_t_x = max_t_y;
	}

	double min_t_z = (minPoint.z() - ray.origin.z()) / ray.direction.z();
	double max_t_z = (maxPoint.z() - ray.origin.z()) / ray.direction.z();

	if (min_t_z > max_t_z) {
		std::swap(min_t_z, max_t_z);
	}

	if ((min_t_x > max_t_z) || (min_t_z > max_t_x)) {
		return false;
	}

	if (min_t_z > min_t_x) {
		min_t_x = min_t_z;
	}
	if (max_t_z < max_t_x) {
		max_t_x = max_t_z;
	}

	// Set our t value
	t = min_t_x;
	Eigen::Vector3d intersection = ray.origin + (t * ray.direction);

	// Find the normal. This is quite simple.
	if (intersection.x() == minPoint.x()) {
		n = Eigen::Vector3d(-1, 0, 0);
	}
	else if (intersection.x() == maxPoint.x()) {
		n = Eigen::Vector3d(1, 0, 0);
	}
	else if (intersection.y() == minPoint.y()) {
		n = Eigen::Vector3d(0, -1, 0);
	}
	else if (intersection.y() == maxPoint.y()) {
		n = Eigen::Vector3d(0, 1, 0);
	}
	else if (intersection.z() == minPoint.z()) {
		n = Eigen::Vector3d(0, 0, 1);
	}
	else if (intersection.z() == maxPoint.z()) {
		n = Eigen::Vector3d(0, 0, -1);
	}
	return (t >= min_t);
}

