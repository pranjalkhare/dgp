#ifndef SHAPE_H
#define SHAPE_H

#include "rule.hpp"
#include "common.hpp"
#include "DGP/AxisAlignedBox3.hpp"

class Shape {
public:
	string type;
	AxisAlignedBox3 bbox;
	Matrix4 transform;
	Rule rule;
	vector<Shape> childs;

	void print();
};

#endif