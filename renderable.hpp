#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "common.hpp"

extern vector<string> renderableList;

class Renderable {
public:
	BBox bbox;

	static Renderable* generateRenderable(string&, BBox);
	virtual void print()=0;
};

class Floors : public Renderable {
public:
	Floors(BBox);
	void print();
};

class Roof : public Renderable {
public:
	Roof(BBox);
	void print();
};

#endif