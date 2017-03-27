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

class Roof : public Renderable {
public:
	Roof(BBox);
	void print();
};

class Wall : public Renderable {
public:
	Wall(BBox);
	void print();
};

class Window : public Renderable {
public:
	Window(BBox);
	void print();
};

class Door : public Renderable {
public:
	Door(BBox);
	void print();
};


#endif