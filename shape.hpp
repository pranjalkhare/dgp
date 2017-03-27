#ifndef SHAPE_H
#define SHAPE_H

#include "rule.hpp"

class Shape {
public:
	string type;
	BBox bbox;
	Rule rule;
	vector<Shape> childs;

	void print();
};

#endif