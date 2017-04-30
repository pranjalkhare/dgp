#include "modeler.hpp"
#include <time.h>

Modeler::Modeler(map<string, RuleSet> rules_) {
	rules = rules_;
}

bool Modeler::isRenderable(string& s) {
	for(int i=0; i<renderableList.size(); i++) {
		if(s == renderableList[i]) {
			return true;
		}
	}
	return false;
}

Rule Modeler::getRule(string& s) {
	
	

	if(rules.find(s)!=rules.end()){
		// return rules[s].rules[0].first;
		RuleSet rs = rules[s];
		double x=rand()%100 * rs.total_weight/100.0;
		double count=0;
		for(int i=0;i<rs.rules.size();i++){
			count+=rs.rules[i].second;
			if(count>=x)return rs.rules[i].first;
		}
		return rs.rules[0].first;

	}
	Rule rule;
	return rule;
}

void Modeler::createChild(string& label, AxisAlignedBox3& bbox, Shape& shape, bool flip) {
	cout<<"Creating "<<label<<endl;
	Shape node;
	node.bbox = bbox;
	node.type = label;
	node.bbox.getLow() = node.bbox.getLow()-bbox.getLow();
	node.bbox.getHigh() = node.bbox.getHigh()-bbox.getLow();
	Matrix3 eye(1,0,0, 0,1,0, 0,0,1);
	// Matrix3 rot(0,0,0, 1,0,0, 0,1,0);
	Matrix3 rot(0,1,0, 1,0,0, 0,0,1);
	if(flip) {
		eye = rot;
		double temp1 = node.bbox.getLow()[1];
		double temp2 = node.bbox.getHigh()[1];
		node.bbox.getLow()[1]=node.bbox.getLow()[0];
		node.bbox.getHigh()[1]=node.bbox.getHigh()[0];
		node.bbox.getLow()[0]=temp1;
		node.bbox.getHigh()[0]=temp2;


	}

	Matrix4 transform(eye, bbox.getLow());
	node.transform = shape.transform*transform;

	// int index;
	if(getRule(label).lhs.size()>0)
		node.rule = getRule(label);
	else if(!isRenderable(label)){
		cerr << "no rule to expand label \"" << label << "\"" << endl;
		exit(0);
	}
	shape.childs.push_back(node);
	cout<<"Child created"<<endl;
}

void Modeler::createChild(string& label, AxisAlignedBox3& bbox, Shape& shape) {
	createChild(label, bbox, shape, false);
}

void Modeler::Comp(Rule& rule, int index, Shape& shape) {
	AxisAlignedBox3 temp;
	temp = shape.bbox;
	temp.getHigh()[1] = temp.getLow()[1];
	createChild(rule.childs[index][0],temp,shape);
	temp = shape.bbox;
	temp.getHigh()[0] = temp.getLow()[0];
	createChild(rule.childs[index][1],temp,shape,true);
	temp = shape.bbox;
	temp.getLow()[1] = temp.getHigh()[1];
	createChild(rule.childs[index][2],temp,shape);
	temp = shape.bbox;
	temp.getLow()[0] = temp.getHigh()[0];
	createChild(rule.childs[index][3],temp,shape,true);
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
	AxisAlignedBox3 bbox = shape.bbox;
	double share = (bbox.getHigh()[ind]-bbox.getLow()[ind])/total;
	bbox.getHigh()[ind] = bbox.getLow()[ind];
	for(int i=0;i<rule.childs[index].size();++i) {
		bbox.getHigh()[ind] += share*stod(rule.params[index][i+1]);
		createChild(rule.childs[index][i],bbox,shape);
		bbox.getLow()[ind] = bbox.getHigh()[ind];
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
	else {
		cerr << "Incorrect dimension specified" << endl;
		exit(1);
	}
	AxisAlignedBox3 bbox = shape.bbox;
	double s = stod(rule.params[index][1]);
	int num = (bbox.getHigh()[ind]-bbox.getLow()[ind])/s;
	double share;
	if(num==0){
		share = (bbox.getHigh()[ind]-bbox.getLow()[ind]);
		num=1;
	}
	else
		share = s + fmod((bbox.getHigh()[ind]-bbox.getLow()[ind]),s)/((double)num);
	bbox.getHigh()[ind] = bbox.getLow()[ind];
	cout<<num<<endl;
	for(int i=0;i<num;++i) {
		bbox.getHigh()[ind] += share;
		createChild(rule.childs[index][0],bbox,shape);
		bbox.getLow()[ind] = bbox.getHigh()[ind];
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
		AxisAlignedBox3 bbox; // To be set accordingly
		bbox.set(shape.transform*shape.bbox.getLow(), shape.transform*shape.bbox.getHigh());
		renderables.push_back(Renderable::generateRenderable(shape.type, bbox));
		return;
	}
	Rule &rule = shape.rule;
	// int index;
	Vector3 stack = {0,0,0};
	AxisAlignedBox3 stackbox;
	for(int i=0; i<rule.functions.size(); i++) {
		cout << "i=" << i << " ";
		cout << "function=" << rule.functions[i] << endl;
		if(rule.functions[i] == "S") {
			stackbox = AxisAlignedBox3(stack, Vector3(stack[0]+stod(rule.params[i][0]),stack[1]+stod(rule.params[i][1]),stack[2]+stod(rule.params[i][2])));
		} else if(rule.functions[i] == "T") {
			stack[0] += stod(rule.params[i][0]);
			stack[1] += stod(rule.params[i][1]);
			stack[2] += stod(rule.params[i][2]);
		} else if(rule.functions[i] == "C") {
			AxisAlignedBox3 bbox = stackbox; // execute stack and set
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
