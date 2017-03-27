#include "renderable.hpp"
vector<string> renderableList = {"roof", "wall", "window", "door"};

Renderable* Renderable::generateRenderable(string& type, AxisAlignedBox3 bbox) {
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

Roof::Roof(AxisAlignedBox3 bbox1) {
	bbox = bbox1;
}

void Roof::print() {
	cout << "Render:\n";
	cout << "Type: roof\n";
	cout << "lo: (" << bbox.getLow()[0] << ", "<< bbox.getLow()[1] << ", "<< bbox.getLow()[2] << ")\n";
	cout << "hi: (" << bbox.getHigh()[0] << ", "<< bbox.getHigh()[1] << ", "<< bbox.getHigh()[2] << ")\n";
}

Wall::Wall(AxisAlignedBox3 bbox1) {
	bbox = bbox1;
}

void Wall::print() {
	cout << "Render:\n";
	cout << "Type: wall\n";
	cout << "lo: (" << bbox.getLow()[0] << ", "<< bbox.getLow()[1] << ", "<< bbox.getLow()[2] << ")\n";
	cout << "hi: (" << bbox.getHigh()[0] << ", "<< bbox.getHigh()[1] << ", "<< bbox.getHigh()[2] << ")\n";
}

Window::Window(AxisAlignedBox3 bbox1) {
	bbox = bbox1;
}

void Window::print() {
	cout << "Render:\n";
	cout << "Type: window\n";
	cout << "lo: (" << bbox.getLow()[0] << ", "<< bbox.getLow()[1] << ", "<< bbox.getLow()[2] << ")\n";
	cout << "hi: (" << bbox.getHigh()[0] << ", "<< bbox.getHigh()[1] << ", "<< bbox.getHigh()[2] << ")\n";
}

Door::Door(AxisAlignedBox3 bbox1) {
	bbox = bbox1;
}

void Door::print() {
	cout << "Render:\n";
	cout << "Type: door\n";
	cout << "lo: (" << bbox.getLow()[0] << ", "<< bbox.getLow()[1] << ", "<< bbox.getLow()[2] << ")\n";
	cout << "hi: (" << bbox.getHigh()[0] << ", "<< bbox.getHigh()[1] << ", "<< bbox.getHigh()[2] << ")\n";
}