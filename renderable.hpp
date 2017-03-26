#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "common.hpp"

extern vector<string> renderableList;

class Renderable {
	static Renderable* generateRenderable(string&, BBox);
	virtual void print()=0;
};

class Floors : public Renderable {
	void print();
};

class Roof : public Renderable {
	void print();
}

#endif