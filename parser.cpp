#include "parser.hpp"
#include <fstream>

Parser::Parser(string& fname) {
	filename = fname;
}

vector<Rule> Parser::parse() {
	string rulestr;
	vector<Rule> p;
	
	fstream fin(filename, ios::in);
	while(getline(fin, rulestr)) {
		if(rulestr[0] == '/') {
			continue;
		}
		p.push_back(getRule(rulestr));
	}
	return p;
}

Rule Parser::getRule(string rulestr) {
	Rule rule;
	int pos = rulestr.find(" ->"), next;
	rule.lhs = rulestr.substr(0, pos);
	pos += 4;

	while(pos < rulestr.size()) {
		next = rulestr.find(" ", pos);
		if(next == -1) {
			next = rulestr.size();
		}
		pushFunction(rule, rulestr.substr(pos, next-pos));
		pos = next+1;
	}

	return rule;
}

void Parser::pushFunction(Rule& rule, string funstr) {
	int pos = funstr.find("("), next;

	if(pos == -1) {
		rule.functions.push_back("C");
		rule.params.push_back(vector<string>());
		rule.childs.push_back(vector<string>(1, funstr));
		return;
	}
	rule.functions.push_back(funstr.substr(0, pos));
	rule.params.push_back(vector<string>());
	rule.childs.push_back(vector<string>());

	vector<string> &params = rule.params[rule.params.size()-1];
	vector<string> &childs = rule.childs[rule.childs.size()-1];
	pos += 1;
	next = funstr.find(")");
	if(pos != next) {
		int temp = funstr.find(",", pos);
		while(temp!=-1 && temp < next) {
			params.push_back(funstr.substr(pos, temp-pos));
			pos = temp+1;
			temp = funstr.find(",", pos);
		}
		params.push_back(funstr.substr(pos, next-pos));
	}

	pos = funstr.find("{")+1;
	next = funstr.find("}");
	if(pos==0 || next == pos) {
		return;
	}

	int temp = funstr.find(",", pos);
	while(temp!=-1) {
		childs.push_back(funstr.substr(pos, temp-pos));
		pos = temp+1;
		temp = funstr.find(",", pos);
	}
	childs.push_back(funstr.substr(pos, next-pos));
}