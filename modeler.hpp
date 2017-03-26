#ifndef MODELER_H
#define MODELER_H

#include "rule.hpp"
#include "shape.hpp"
#include "renderable.hpp"

class Modeler {
public:
	vector<Rule> rules;
	Modeler(vector<Rule>);
	bool isRenderable(string& s);
	int isFunction(string& s);
	void getRenderable(vector<Renderable>& renderables, Shape& shape);
};

#endif