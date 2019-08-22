#include <iostream>
#include <getopt.h>
#include "config.h"


int main(int argc, char *argv[])
{
	// Argument counter
	int cc;

	// No errors from getopt (flag)
	opterr=0;

	// Argument parsing loop
	while(true)
	{
		// Declaration of long arguments
		static struct option options[] =
		{
			{"help", no_argument, 0, 'h'},
			{"output", required_argument, 0, 'o'},
			{0,0,0,0}
		};

		int option_index = 0;

		// The actual parsing
		cc = getopt_long(argc, argv, "ho:", options, &option_index);

		// No more parseable arguments
		if(cc == -1)
		{
			break;
		}
		// Argument switch table
		switch(cc)
		{
			case 'h':
				std::cout << "Ayuda\n";
				break;
			case 'o':
				std::cout << "-->" << optarg << '\n';
				break;
			case '?':
				std::cerr << "No\n";
				break;
		}
	}
	return 0;
}
