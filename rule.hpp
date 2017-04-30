#ifndef RULE_H
#define RULE_H

#include "common.hpp"
using namespace std;

class Rule {
public:
	string lhs;
	vector<string> functions;
	vector<vector<string> > params;
	vector<vector<string> > childs;
	double weight;

	void print() {
		cout << "lhs= " << lhs << endl;

		for(int i=0; i<functions.size(); i++) {
			cout << "\t" << functions[i] << endl;
			cout << "\t" << "params: " << params[i].size() << endl;
			for(int j=0; j<params[i].size(); j++) {
				cout << "\t\t" << j << "-> " << params[i][j] << endl;
			}	
			cout << "\t" << "childs: " << childs[i].size() << endl;
			for(int j=0; j<childs[i].size(); j++) {
				cout << "\t\t" << j << "-> " << childs[i][j] << endl;
			}
		}
	}
};

class RuleSet{
public:
	string lhs;
	double total_weight;
	vector<pair<Rule, double> > rules;
};

#endif