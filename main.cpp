#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <string>

#include "node.h"


/// The main entry point for the application
/// argc - the number of command line parameters.  This will always be at least 1
/// argv - the command line parameters.  The first parameter is always the name of the application
int main(int argc, char** argv)
{
	// To run the program, it requires 3 command line parameters:
	// argv[0] - the application name
	// argv[1] - the port input file
	// argv[2] - the nodes input file
	// argv[3] - the output file
	if (argc != 3) {
		std::cout << "Usage:  app [nodes input file] [output file]" << std::endl;
		return 0;
	}

	// Create the input streams
	//std::ifstream finPorts(argv[1]);
	std::ifstream finNodes(argv[1]);

	// Create the output stream
	std::ofstream fout(argv[2]);

	Node node;
	//node.LoadPorts(finPorts);
	node.LoadNodes(finNodes);
	node.Report(fout);

	return 0;
}
