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
  root.bbox.lo.x = 0;
  root.bbox.lo.y = 0;
  root.bbox.lo.z = 0;
  root.bbox.hi.x = 0;
  root.bbox.hi.y = 0;
  root.bbox.hi.z = 0;
  root.type = modeler.rules[0].lhs;
  root.rule = modeler.rules[0];

  vector<Renderable*> renderables;
  modeler.getRenderable(renderables, root);
  cout << "yo" << renderables.size();
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