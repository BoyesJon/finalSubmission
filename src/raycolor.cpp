#include "raycolor.h"
#include "first_hit.h"
#include "blinn_phong_shading.h"
#include "reflect.h"

bool raycolor(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector< std::shared_ptr<Light> > & lights,
  const int num_recursive_calls,
  Eigen::Vector3d & rgb)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  rgb = Eigen::Vector3d(0,0,0);

  // If we have called this function 10 times, stop calling the function.
  if (num_recursive_calls == 10) {
	  return true;
  }

  // Setup values. We are going to set our ambient light value to be (1, 1, 1).
  int hitVal;
  double t;
  Eigen::Vector3d n;
  Eigen::Vector3d ambientLight = Eigen::Vector3d(1, 1, 1);
  bool foundHit = first_hit(ray, min_t, objects, hitVal, t, n);
  // If we found a hit, grab the colour info for this object.
  if (foundHit) {
	  // Find the rgb values using Blinn Phong shading
	  n.normalize();
	  rgb = (objects[hitVal]->material->ka.array() * ambientLight.array()).matrix();
	  Eigen::Vector3d blinnPhongShading = blinn_phong_shading(ray, hitVal, t, n, objects, lights);
	  rgb += blinnPhongShading;
	  
	  // Next, find the reflected value. We need the hit location for this, since we are building
	  // a new "reflected" ray.
	  
	  Eigen::Vector3d hitPoint = ray.origin + (t * ray.direction);
	  Eigen::Vector3d normalizedViewing = ray.direction;
	  normalizedViewing.normalize();
	  Eigen::Vector3d reflectedDir = reflect(normalizedViewing, n);
	  Eigen::Vector3d reflectedColour;
	  Eigen::Vector3d reflectedColourFinal;

	  // Find the reflected colour result.
	  Ray reflectedRay;
	  reflectedRay.direction = reflectedDir;
	  reflectedRay.origin = hitPoint;
	  bool recurse = raycolor(reflectedRay, 1e-07, objects, lights, num_recursive_calls + 1, reflectedColour);
	  reflectedColourFinal = (objects[hitVal]->material->km.array() * reflectedColour.array()).matrix();
	  rgb += reflectedColourFinal;
	  return true;
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
