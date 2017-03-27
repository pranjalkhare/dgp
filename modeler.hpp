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
	int getRule(string& s);
	void getRenderable(vector<Renderable*>& renderables, Shape& shape);
	void createChild(string& label, BBox &bbox, Shape& shape);
	void Comp(Rule& rule, int index, Shape& shape);
	void SubDiv(Rule& rule, int index, Shape& shape);
	void Repeat(Rule& rule, int index, Shape& shape);
};

#endif