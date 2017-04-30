#include "rule.hpp"

class Parser {
	string filename;
public:
	Parser(string&);
	void parse(map<string, RuleSet> &rules);
	void getRule(string rulestr, Rule &rule);
	void pushFunction(Rule& rule, string funstr);
};