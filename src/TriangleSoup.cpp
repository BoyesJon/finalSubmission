#include "TriangleSoup.h"
#include "Ray.h"
// Hint
#include "first_hit.h"

bool TriangleSoup::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
	// Rather than using the same code as in first_hit, just call first_hit on the triangle soup.
	int hit_id_holder = 0;
	Eigen::Vector3d temp_n;
	double temp_t;
	bool triangleHit = first_hit(ray, min_t, triangles, hit_id_holder, temp_t, temp_n);
	if (triangleHit) {
		t = temp_t;
		n = temp_n;
	}
	return triangleHit;

  ////////////////////////////////////////////////////////////////////////////
}



