#include "parser.hpp"
#include <fstream>

Parser::Parser(string& fname) {
	filename = fname;
}

void Parser::parse(map<string, RuleSet> &rules) {
	string rulestr;
	// vector<Rule> p;
	
	fstream fin(filename, ios::in);
	while(getline(fin, rulestr)) {
		if(rulestr[0] == '/') {
			continue;
		}

		// if(rules.find(rulestr!=rules.end())
		// rules[l]
		Rule rule;
		cout<<rulestr<<endl;
		getRule(rulestr, rule);
		cout<<rulestr<<endl;
		if(rules.find(rule.lhs)==rules.end()){
			RuleSet rs;
			rs.rules = vector<pair<Rule, double> >(1,pair<Rule, double>(rule,rule.weight));
			rs.lhs = rule.lhs;
			rs.total_weight = rule.weight;
			rules[rule.lhs] = rs;
		}
		else{
			rules[rule.lhs].rules.push_back(pair<Rule, double>(rule, rule.weight));
			rules[rule.lhs].total_weight+=rule.weight;
		}	
	}
}

void Parser::getRule(string rulestr, Rule &rule) {
	int pos = rulestr.find(" ->"), next;
	rule.lhs = rulestr.substr(0, pos);
	pos += 4;
	int pos2 = rulestr.find(":");
	if(pos2==-1) {
		pos2=rulestr.size();
		rule.weight =1;
	}
	else{
		rule.weight = stod(rulestr.substr(pos2+1,rulestr.size()-pos2-1));
	}
	while(pos < pos2) {
		next = rulestr.find(" ", pos);
		if(next == -1) {
			next = rulestr.size();
		}
		pushFunction(rule, rulestr.substr(pos, next-pos));
		pos = next+1;
	}

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