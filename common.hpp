#ifndef COMMON_H
#define COMMON_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Point {
	int x, y, z;
	// std::ostream &
	// operator<<(std::ostream & os, VectorN<N, T> const & v)
	// {
	//   return os << v.toString();
	// }
};

struct BBox {
	Point lo, hi;
};

#endif