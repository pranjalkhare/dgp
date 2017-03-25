#include <parser.h>


int
usage(int argc, char * argv[])
{
  DGP_CONSOLE << "";
  DGP_CONSOLE << "Usage: " << argv[0] << " [filename] \n";

  return -1;
}

int
main(int argc, char * argv[])
{
  if (argc < 2)
    return usage(argc, argv);
}
	// take as input grammar file 

	// create parser object

	// run parser.parse : generates map<string,...> of rules

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
// 	process(list<renderableObjects>& lst);
// }