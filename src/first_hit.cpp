#include "first_hit.h"

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
	// To find the first hit, we will iterate through the object list.
	// We will then return the id of the first hit, as well as the resultant
	// "t" value, and the location in 3D Space "n".
	int objectCount = 0;
	double temp_t = INT_MAX;
	Eigen::Vector3d temp_n;
	bool foundHit = false;
	for (int i = 0; i < (int)objects.size(); i++) {
		// used to store the t and n values of the current object
		double object_t;
		Eigen::Vector3d object_n;
		bool intersectFound = objects[i]->intersect(ray, min_t, object_t, object_n);

		// Find out if the ray intersects with the current object.
		// If so, check if the current object is the closest one (smallest current t value).
		// If both of these are true, then store the results, and let the program know
		// that an object was intersected.
		if (intersectFound) {
			if (object_t <= temp_t) {
				hit_id = objectCount;
				temp_t = object_t;
				temp_n = object_n;
				foundHit = true;
			}
		}

		// Increase objectCount
		objectCount++;
	}
  t = temp_t;
  n = temp_n;
  return foundHit;
  ////////////////////////////////////////////////////////////////////////////
}

