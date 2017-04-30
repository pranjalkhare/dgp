#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "common.hpp"
#include "DGP/AxisAlignedBox3.hpp"
#include "DGP/Graphics/RenderSystem.hpp"


extern vector<string> renderableList;

class Renderable {
public:
	AxisAlignedBox3 bbox;

	static Renderable* generateRenderable(string&, AxisAlignedBox3);
	virtual void print()=0;
	virtual void draw(Graphics::RenderSystem & rs, ColorRGBA const & plane_color = ColorRGB(1.0, 1.0, 1.0))  = 0;

};

class Roof : public Renderable {
public:
	Roof(AxisAlignedBox3);
	void print();
	void draw(Graphics::RenderSystem & rs, ColorRGBA const & plane_color = ColorRGB(1.0, 0.0, 0.0)) ;
};

class Wall : public Renderable {
public:
	Wall(AxisAlignedBox3);
	void print();
	void draw(Graphics::RenderSystem & rs, ColorRGBA const & plane_color = ColorRGB(1.0, 1.0, 1.0)) ;
};

class Win : public Renderable {
public:
	Win(AxisAlignedBox3);
	void print();
	void draw(Graphics::RenderSystem & rs, ColorRGBA const & plane_color = ColorRGB(0.0, 0.0, 1.0)) ;
};

class Door : public Renderable {
public:
	Door(AxisAlignedBox3);
	void print();
	void draw(Graphics::RenderSystem & rs, ColorRGBA const & plane_color = ColorRGB(0.0, 1.0, 0.0)) ;
};


#endif