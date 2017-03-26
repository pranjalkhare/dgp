#ifndef COMMON_H
#define COMMON_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Point {
	int x, y, z;
};

struct BBox {
	Point lo, hi;	
	
};

#endif