#include "renderable.hpp"
vector<string> renderableList = {"roof", "floors"};

Renderable* Renderable::generateRenderable(string& type, BBox bbox) {
	Renderable* retval;
	// if()

	return retval;
}

void Floor::print() {
	cout << "Render:\n";
	cout << "Type: floor\n";
	cout << "lo: " << bbox.lo << "\n";
	cout << "hi: " << bbox.hi << "\n";


}