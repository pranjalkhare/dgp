#include "rule.hpp"

class Parser {
	string filename;
public:
	Parser(string&);
	vector<Rule> parse();
	Rule getRule(string rulestr);
	void pushFunction(Rule& rule, string funstr);
};