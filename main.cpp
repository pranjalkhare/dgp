#include "parser.hpp"


int
usage(int argc, char * argv[])
{
  cout << "";
  cout << "Usage: " << argv[0] << " [filename] \n";

  return -1;
} 

int
main(int argc, char * argv[])
{
  if (argc < 2)
    return usage(argc, argv);

  vector<Rule> rules;
  string filename(argv[1]);
  Parser parser(filename);
  rules = parser.parse();

	for(int i=0; i<rules.size(); i++) {
		rules[i].print();
	}


}
	// take as input grammar file 

	// create parser object

	// run parser.parse : generates a vector of rules

	// create tree object: set first rule as root
	// create queue of terminal objects (initially empty)
	// call model function on root: populates term obj queue

	// List of supported functions:
	/*
		S
		T
		SubDiv
		Repeat
		Comp

		Roof
		Floors
		Facade
		Side
			floors
				floor
					tiles
						tile
							window
							wall
			gfloor
				tiles
					tile
						window
						wall
				entrance
					door
					wall	

	*/

	// call render with the queue

// class shape {
// public:
// 	process(list<renderableObjects>& lst, vector<Rule> rules);
// }