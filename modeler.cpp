#include "modeler.hpp"

Modeler::Modeler(vector<Rule> rules1) {
	rules = rules1;
}

bool Modeler::isRenderable(string& s) {
	for(int i=0; i<renderableList.size(); i++) {
		if(s == renderableList[i]) {
			return true;
		}
	}
	return false;
}

int Modeler::getRule(string& s) {
	for(int i=0; i<rules.size(); i++) {
		if(rules[i].lhs == s) {
			return i;
		}
	}
	return -1;
}

void Modeler::createChild(string& label, BBox& bbox, Shape& shape) {
	Shape node;
	node.bbox = bbox;
	node.type = label;
	int index;
	if((index = getRule(label)) >= 0)
		node.rule = rules[index];
	else if(!isRenderable(label)){
		cerr << "no rule to expand label \"" << label << "\"" << endl;
		exit(0);
	}
	shape.childs.push_back(node);
	cout<<"Child created"<<endl;
}

void Modeler::Comp(Rule& rule, int index, Shape& shape) {
	BBox temp;
	temp = shape.bbox;
	temp.hi.p[1] = temp.lo.p[1];
	createChild(rule.childs[index][0],temp,shape);
	temp = shape.bbox;
	temp.hi.p[0] = temp.lo.p[0];
	createChild(rule.childs[index][1],temp,shape);
	temp = shape.bbox;
	temp.lo.p[1] = temp.hi.p[1];
	createChild(rule.childs[index][2],temp,shape);
	temp = shape.bbox;
	temp.lo.p[0] = temp.hi.p[0];
	createChild(rule.childs[index][3],temp,shape);
	cout<<"Comp Completed"<<endl;
}

void Modeler::SubDiv(Rule& rule, int index, Shape& shape) {
	if(rule.params[index].size() != rule.childs[index].size()+1) {
		cerr << "number of params does not match number of children in rule" << endl;
		exit(0);
	}
	int ind;
	if(rule.params[index][0] == "X")
		ind = 0;
	else if(rule.params[index][0] == "Y")
		ind = 1;
	else if(rule.params[index][0] == "Z")
		ind = 2;
	double total=0;
	for(int i=1;i<rule.params[index].size();++i){
		total += stod(rule.params[index][i]);
	}
	if(total==0)
		total=1;
	BBox bbox = shape.bbox;
	double share = (bbox.hi.p[ind]-bbox.lo.p[ind])/total;
	bbox.hi.p[ind] = bbox.lo.p[ind];
	for(int i=0;i<rule.childs[index].size();++i) {
		bbox.hi.p[ind] += share*stod(rule.params[index][i+1]);
		createChild(rule.childs[index][i],bbox,shape);
		bbox.lo = bbox.hi;
	}
	cout<<"SubDiv Completed"<<endl;
}

void Modeler::Repeat(Rule& rule, int index, Shape& shape) {
	if(rule.params[index].size() != 2 || rule.childs[index].size() != 1) {
		cerr << "improper format of Repeat function." << endl;
		cerr << "usage: Repeat(dimension,size){label}" << endl;
		exit(0); 
	}
	int ind;
	if(rule.params[index][0] == "X")
		ind = 0;
	else if(rule.params[index][0] == "Y")
		ind = 1;
	else if(rule.params[index][0] == "Z")
		ind = 2;
	BBox bbox = shape.bbox;
	double s = stod(rule.params[index][1]);
	int num = (bbox.hi.p[ind]-bbox.lo.p[ind])/s;
	double share;
	if(num==0){
		share = (bbox.hi.p[ind]-bbox.lo.p[ind]);
		num=1;
	}
	else
		share = s + fmod((bbox.hi.p[ind]-bbox.lo.p[ind]),s)/((double)num);
	bbox.hi.p[ind] = bbox.lo.p[ind];
	cout<<num<<endl;
	for(int i=0;i<num;++i) {
		bbox.hi.p[ind] += share;
		createChild(rule.childs[index][0],bbox,shape);
		bbox.lo = bbox.hi;
	}
	cout<<"Repeat Completed"<<endl;
}

void Modeler::getRenderable(vector<Renderable*>& renderables, Shape& shape) {

	// Needs to be fixed
	cout<<endl;
	cout<<"*********************Node Started*******************************"<<endl;
	cout<<endl;
	shape.print();

	if(isRenderable(shape.type)) {
		cout<<"Root Node >>>>>>>>>>>>>>>>>>>>>>>>>>>> "<<shape.type<<endl;
		cout<<endl;
		cout<<"*********************Node Done*******************************"<<endl;
		cout<<endl;
		BBox bbox; // To be set accordingly
		renderables.push_back(Renderable::generateRenderable(shape.type, bbox));
		return;
	}
	Rule &rule = shape.rule;
	int index;
	Point stack;
	BBox stackbox;
	for(int i=0; i<rule.functions.size(); i++) {
		cout << "i=" << i << " ";
		cout << "function=" << rule.functions[i] << endl;
		if(rule.functions[i] == "S") {
			stackbox = BBox(stack, Point(stack.p[0]+stod(rule.params[i][0]),stack.p[1]+stod(rule.params[i][1]),stack.p[2]+stod(rule.params[i][2])));
		} else if(rule.functions[i] == "T") {
			stack.p[0] += stod(rule.params[i][0]);
			stack.p[1] += stod(rule.params[i][1]);
			stack.p[2] += stod(rule.params[i][2]);
		} else if(rule.functions[i] == "C") {
			BBox bbox = stackbox; // execute stack and set
			for(int j=0;j<rule.childs[i].size();++j) {
				createChild(rule.childs[i][j],bbox,shape);
			}
		} else if(rule.functions[i] == "Comp") {
			Comp(rule,i,shape);
		} else if(rule.functions[i] == "SubDiv") {
			SubDiv(rule,i,shape);
		} else if(rule.functions[i] == "Repeat") {
			Repeat(rule,i,shape);
		} else {
			cerr << "unknown function: " << rule.functions[i] << endl;
			exit(0);
		}
	}

	cout<<endl;
	cout<<"*********************Node Done*******************************"<<endl;
	cout<<endl;

	// go through children
	for(int i=0;i<shape.childs.size();++i){
		getRenderable(renderables,shape.childs[i]);
	}
}
