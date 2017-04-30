#include "parser.hpp"
#include "modeler.hpp"
#include "rule.hpp"
#include "shape.hpp"
#include "Viewer.hpp"


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
  srand(time(NULL));
  string filename(argv[1]);
  Parser parser(filename);
  map<string, RuleSet> rules;
  parser.parse(rules);
  Modeler modeler(rules);

  // for(int i=0; i<modeler.rules.size(); i++) {
  	// modeler.rules[i].print();
  // }

  Shape root;
  root.rule = modeler.rules["footprint"].rules[0].first;
  root.type = "footprint";
  root.transform.fill(0);
  root.transform.set(0,0,1);
  root.transform.set(1,1,1);
  root.transform.set(2,2,1);
  root.transform.set(3,3,1);
  // cout << root.transform;

  vector<Renderable*> renderables;
  modeler.getRenderable(renderables, root);
  for(auto i:root.childs) {
    root.bbox.merge(i.transform*i.bbox.getLow());
    root.bbox.merge(i.transform*i.bbox.getHigh());
  }
  root.print();
  cout << "Total Renderable Elements: " << renderables.size() << endl;

  Viewer viewer;
  viewer.setObject(&root);
  viewer.setRenderables(renderables);
  viewer.launch(argc, argv);
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
