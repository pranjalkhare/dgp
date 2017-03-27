#include "parser.hpp"
#include "modeler.hpp"
#include "rule.hpp"
#include "shape.hpp"

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

  string filename(argv[1]);
  Parser parser(filename);
  Modeler modeler(parser.parse());

  for(int i=0; i<modeler.rules.size(); i++) {
  	modeler.rules[i].print();
  }

  Shape root;
  root.type = modeler.rules[0].lhs;
  root.rule = modeler.rules[0];
  root.transform.fill(0);
  root.transform.set(0,0,1);
  root.transform.set(1,1,1);
  root.transform.set(2,2,1);
  root.transform.set(3,3,1);
  // cout << root.transform;

  vector<Renderable*> renderables;
  modeler.getRenderable(renderables, root);
  cout << "Total Renderable Elements: " << renderables.size() << endl;
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
