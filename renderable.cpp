#include "renderable.hpp"
vector<string> renderableList = {"roof", "wall", "window", "door"};

Renderable* Renderable::generateRenderable(string& type, BBox bbox) {
	Renderable* retval;
	if(type == "roof") {
		retval = new Roof(bbox);
	} else if(type == "wall") {
		retval = new Wall(bbox);
	} else if(type == "window") {
		retval = new Window(bbox);
	} else if(type == "door") {
		retval = new Door(bbox);
	} else {
		cerr << "Unknown type for rendering" << endl;
		exit(0);
	}

	return retval;
}

Roof::Roof(BBox bbox1) {
	bbox = bbox1;
}

void Roof::print() {
	cout << "Render:\n";
	cout << "Type: roof\n";
	cout << "lo: (" << bbox.lo.p[0] << ", "<< bbox.lo.p[1] << ", "<< bbox.lo.p[2] << ")\n";
	cout << "hi: (" << bbox.hi.p[0] << ", "<< bbox.hi.p[1] << ", "<< bbox.hi.p[2] << ")\n";
}

Wall::Wall(BBox bbox1) {
	bbox = bbox1;
}

void Wall::print() {
	cout << "Render:\n";
	cout << "Type: wall\n";
	cout << "lo: (" << bbox.lo.p[0] << ", "<< bbox.lo.p[1] << ", "<< bbox.lo.p[2] << ")\n";
	cout << "hi: (" << bbox.hi.p[0] << ", "<< bbox.hi.p[1] << ", "<< bbox.hi.p[2] << ")\n";
}

Window::Window(BBox bbox1) {
	bbox = bbox1;
}

void Window::print() {
	cout << "Render:\n";
	cout << "Type: window\n";
	cout << "lo: (" << bbox.lo.p[0] << ", "<< bbox.lo.p[1] << ", "<< bbox.lo.p[2] << ")\n";
	cout << "hi: (" << bbox.hi.p[0] << ", "<< bbox.hi.p[1] << ", "<< bbox.hi.p[2] << ")\n";
}

Door::Door(BBox bbox1) {
	bbox = bbox1;
}

void Door::print() {
	cout << "Render:\n";
	cout << "Type: door\n";
	cout << "lo: (" << bbox.lo.p[0] << ", "<< bbox.lo.p[1] << ", "<< bbox.lo.p[2] << ")\n";
	cout << "hi: (" << bbox.hi.p[0] << ", "<< bbox.hi.p[1] << ", "<< bbox.hi.p[2] << ")\n";
}