#include "blinn_phong_shading.h"
// Hint:
#include "first_hit.h"
#include <iostream>

Eigen::Vector3d blinn_phong_shading(
  const Ray & ray,
  const int & hit_id, 
  const double & t,
  const Eigen::Vector3d & n,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector<std::shared_ptr<Light> > & lights)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
	// Starting values
	Eigen::Vector3d newColour = Eigen::Vector3d(0, 0, 0);
	Eigen::Vector3d hitPoint = ray.origin + (t * ray.direction);
	Eigen::Vector3d normRayDir = -ray.direction;
	normRayDir.normalize();

	for (int i = 0; i < (int)lights.size(); i++) {
		int hitValTemp;
		double temp_t;
		double max_t;
		Ray lightRay;
		Eigen::Vector3d lightDir;
		Eigen::Vector3d temp_n;

		// Create the "light" ray, find out if it intersects with any objects.
		lights[i]->direction(hitPoint, lightDir, max_t);
		lightRay.direction = lightDir;
		lightRay.origin = hitPoint;
	
		bool foundLightHit = first_hit(lightRay, 1e-7, objects, hitValTemp, temp_t, temp_n);
		if (!(foundLightHit && temp_t >= 1e-7 && temp_t < max_t)) {
			// We didn't find any blocking objects, so let's calculate the final colour
			// New check: Is the light dim?
			Eigen::Vector3d lightColour = lights[i]->I;
			if (lights[i]->isDim) {
				// If it is, calculate it's "Light Attenuation".
				// Algorithm adapted from https://imdoingitwrong.wordpress.com/2011/01/31/light-attenuation/
				double distance = (lightDir + hitPoint).norm();
				double kl = 2 / lights[i]->lightRadius;
				double kq = 1 / std::pow(lights[i]->lightRadius, 2);
				double attenuationDenom = 1 + (kl * distance) + (kq * std::pow(distance, 2));
				double attenuationResult = 1 / attenuationDenom;
				lightColour = lightColour * attenuationResult;
			}
			Eigen::Vector3d halfwayVec;
			lightDir.normalize();
			halfwayVec = (lightDir + normRayDir);
			halfwayVec.normalize();
			double diffuseMax = std::fmax(0, n.dot(lightDir));
			double specularMax = std::fmax(0, n.dot(halfwayVec));

			Eigen::Vector3d diffuseVal = (objects[hit_id]->material->kd.array() * lightColour.array()).matrix() * diffuseMax;
			Eigen::Vector3d specularVal = (objects[hit_id]->material->ks.array() * lightColour.array()).matrix() * std::pow(specularMax, objects[hit_id]->material->phong_exponent);
			
			newColour = newColour + diffuseVal + specularVal;
		}
	}
  return newColour;
  ////////////////////////////////////////////////////////////////////////////
}
