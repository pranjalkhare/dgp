#ifndef MODELER_H
#define MODELER_H

#include "rule.hpp"
#include "shape.hpp"
#include "renderable.hpp"
#include "common.hpp"
#include "DGP/AxisAlignedBox3.hpp"

class Modeler {
public:
	map<string, RuleSet> rules;
	Modeler(map<string, RuleSet>);
	bool isRenderable(string& s);
	Rule getRule(string& s);
	void getRenderable(vector<Renderable*>& renderables, Shape& shape);
	void createChild(string& label, AxisAlignedBox3 &bbox, Shape& shape, bool flip);
	void createChild(string& label, AxisAlignedBox3 &bbox, Shape& shape);
	void Comp(Rule& rule, int index, Shape& shape);
	void SubDiv(Rule& rule, int index, Shape& shape);
	void RepeatAbs(Rule& rule, int index, Shape& shape);
	void Repeat(Rule& rule, int index, Shape& shape);
};

#endif