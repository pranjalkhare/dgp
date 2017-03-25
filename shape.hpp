#include <rule>

struct Point {
	int x, y, z;
};

class Shape {
public:
	Point lo, hi;
	Rule rule;
	vector<Shape> childs;

	void getRenderable(vector<Renderable>& render_vector, vector<Rule> rules) {
		// Goes through the functions
		// For every function
			// check for S/T
			// 
	}

};