#ifndef COMMON_H
#define COMMON_H

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

struct Point {
public:
	vector<double> p;

	Point() {
		p = vector<double>(3,0);
	}

	Point(double _x, double _y, double _z) {
		p = vector<double>(3,0);
		p[0]=_x;p[1]=_y;p[2]=_z;
	}
	// std::ostream &
	// operator<<(std::ostream & os, VectorN<N, T> const & v)
	// {
	//   return os << v.toString();
	// }
};

struct BBox {
public:
	Point lo, hi;

	BBox() {
		lo = Point();
		hi = Point();
	}

	BBox(Point _lo, Point _hi) {
		lo=_lo;hi=_hi;
	}
};

#endif