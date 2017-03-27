#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "common.hpp"
#include "DGP/AxisAlignedBox3.hpp"

extern vector<string> renderableList;

class Renderable {
public:
	AxisAlignedBox3 bbox;

	static Renderable* generateRenderable(string&, AxisAlignedBox3);
	virtual void print()=0;
};

class Roof : public Renderable {
public:
	Roof(AxisAlignedBox3);
	void print();
};

class Wall : public Renderable {
public:
	Wall(AxisAlignedBox3);
	void print();
};

class Window : public Renderable {
public:
	Window(AxisAlignedBox3);
	void print();
};

class Door : public Renderable {
public:
	Door(AxisAlignedBox3);
	void print();
};


#endif