#include <iostream>
#include <getopt.h>
#include "config.h"

// Display help
void help(char**);

int main(int argc, char *argv[])
{
	// Argument counter
	int cc;

	// No errors from getopt (flag)
	opterr=0;

	// Implicit help when no arguments are passed
	if(argc == 1)
	{
		help(argv);
		exit(2);
	}

	// Declaration of long arguments{{{
	static struct option options[] =
	{
		{"help", no_argument, 0, 'h'},
		{"input", required_argument, 0, 'i'},
		{0,0,0,0}
	};
	//}}}
	// Argument parsing loop{{{
	while(true)
	{
		int option_index = 0;

		// The actual parsing
		cc = getopt_long(argc, argv, "hi:", options, &option_index);

		// No more parseable arguments{{{
		if(cc == -1)
		{
			break;
		}
		//}}}
		// Argument switch table{{{
		switch(cc)
		{
			case 'h':
				help(argv);
				break;
			case 'i':
				//Input
				break;
			case '?':
				std::cerr << "No\n";
				break;
		}
		//}}}
	}
	//}}}
	return 0;
}

// Help{{{
void help(char* argv[])
{
	std::cout << "Uso:\n"
		<< "    " << argv[0] << " [opción]\n"
		<< "Opciones:\n"
		<< "    " << "-h, --help             Muestra la ayuda\n"
		<< "    " << "-i, --input=TEXTO      Input del programa\n";
}
// }}}
