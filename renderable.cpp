#include "renderable.hpp"
vector<string> renderableList = {"roof", "floors"};

Renderable* Renderable::generateRenderable(string& type, BBox bbox) {
	Renderable* retval;
	if(type == "roof") {
		retval = new Roof(bbox);
	} else if(type == "floors") {
		retval = new Floors(bbox);
	} else {
		cerr << "Unknown type for rendering" << endl;
		exit(0);
	}

	return retval;
}

Floors::Floors(BBox bbox1) {
	bbox = bbox1;
}

void Floors::print() {
	cout << "Render:\n";
	cout << "Type: floor\n";
	cout << "lo: (" << bbox.lo.x << ", "<< bbox.lo.y << ", "<< bbox.lo.z << ")\n";
	cout << "hi: (" << bbox.hi.x << ", "<< bbox.hi.y << ", "<< bbox.hi.z << ")\n";
}

Roof::Roof(BBox bbox1) {
	bbox = bbox1;
}

void Roof::print() {
	cout << "Render:\n";
	cout << "Type: roof\n";
	cout << "lo: (" << bbox.lo.x << ", "<< bbox.lo.y << ", "<< bbox.lo.z << ")\n";
	cout << "hi: (" << bbox.hi.x << ", "<< bbox.hi.y << ", "<< bbox.hi.z << ")\n";
}