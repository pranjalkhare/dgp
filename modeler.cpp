#include "modeler.hpp"

Modeler::Modeler(vector<Rule> rules1) {
	rules = rules1;
}

bool Modeler::isRenderable(string& s) {
	for(int i=0; i<renderableList.size(); i++) {
		cout << "yoooo";
		if(s == renderableList[i]) {
			return true;
		}
	}
	return false;
}

int Modeler::isFunction(string& s) {
	for(int i=0; i<rules.size(); i++) {
		if(rules[i].lhs == s) {
			return i;
		}
	}
	cout << "end isFunction" << endl;
	return -1;
}

void Modeler::getRenderable(vector<Renderable*>& renderables, Shape& shape) {

	// Needs to be fixed

	Rule &rule = shape.rule;
	int index;
	for(int i=0; i<rule.functions.size(); i++) {
		cout << "i=" << i << endl;
		cout << "function=" << rule.functions[i] << endl;
		if(rule.functions[i] == "S" || rule.functions[i] == "T") {

		} else if(rule.functions[i] == "C") {

		} else if(isRenderable(rule.functions[i])) {
			cout << "yooo";
			BBox bbox; // To be set accordingly
			renderables.push_back(Renderable::generateRenderable(rule.functions[i], bbox));
		} else if((index = isFunction(rule.functions[i])) >= 0) {

		} else {
			cerr << "unknown function: " << rule.functions[i] << endl;
			exit(0);
		}
	}
}
