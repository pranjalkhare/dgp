#include "common.hpp"
using namespace std;

class Rule {
public:
	string lhs;
	vector<string> functions;
	vector<vector<string> > params;
	vector<vector<string> > childs;

	void print() {
		cout << "lhs= " << lhs << endl;

		for(int i=0; i<functions.size(); i++) {
			cout << functions[i] << endl;
			cout << "params: " << params[i].size() << endl;
			for(int j=0; j<params[i].size(); j++) {
				cout << j << "-> " << params[i][j] << endl;
			}	
			cout << "childs: " << childs[i].size() << endl;
			for(int j=0; j<childs[i].size(); j++) {
				cout << j << "-> " << childs[i][j] << endl;
			}	
		}
		// cout << "params: " << endl;
		// for(int i=1; i<=params.size(); i++) {
		// 	cout << i << "-> " << endl;
		// 	for(int j=0; j<params[i].size(); j++) {
		// 		cout << "    " << j << ": " << params[i][j] << endl;
		// 	}
		// }
		// cout << "childs: " << endl;
		// for(int i=1; i<=childs.size(); i++) {
		// 	cout << i << "-> " << endl;
		// 	for(int j=0; j<childs[i].size(); j++) {
		// 		cout << "    " << j << ": " << childs[i][j] << endl;
		// 	}
		// }
	}
};