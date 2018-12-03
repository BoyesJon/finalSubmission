#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code from computer-graphics-raster-images or email
  // jacobson@cs.toronto.edu for correct code.
  assert(
    (num_channels == 3 || num_channels ==1 ) &&
    ".ppm only supports RGB or grayscale images");
  std::ofstream file;
  file.open(filename);
  // Check if the file is open. If so, begin copying data.
  if (file.is_open()) {
	  file << "P3" << std::endl << width << std::endl << height << std::endl << "255" << std::endl;
	  if (num_channels == 3) {
		  for (int y = 0; y < height; y++) {
			  for (int x = 0; x < width; x++) {
				  int red = data[3 * (x + width * y)];
				  int grn = data[1 + 3 * (x + width * y)];
				  int blu = data[2 + 3 * (x + width * y)];
				  file << red << " " << grn << " " << blu << std::endl;
			  }
		  }
	  }
	  else {
		  for (int y = 0; y < height; y++) {
			  for (int x = 0; x < width; x++) {
				  int gry = data[x + width * y];
				  file << gry << " " << gry << " " << gry << std::endl;
			  }
		  }
	  }
	  file.close();
	  return true;
  }
  else {
	  // The file could not open; return false.
	  return false;
  }
  ////////////////////////////////////////////////////////////////////////////
}
