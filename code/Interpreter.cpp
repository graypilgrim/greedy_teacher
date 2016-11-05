#include "Interpreter.hpp"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <getopt.h>

Interpreter::Interpreter(int argc, char *argv[])
	:manual(true), testsNo(0), childrenNo(0), maxResult(0)
{
	int opt;

	while ((opt = getopt(argc, argv, "ha:c:r:")) != EOF)
	{
		switch (opt) {
		case 'h':
			PrintHelp();
			exit(0);
			break;

		case 'a':
			manual = false;
			testsNo = atol(optarg);
			break;

		case 'c':
			childrenNo = atol(optarg);
			break;

		case 'r':
			maxResult = atol(optarg);
			break;

		case '?':
			PrintHelp();

		default:
			std::cout << std::endl;
			abort();
		}
	}

	if (manual == true)
		RunManualTester();
}

void Interpreter::PrintHelp()
{
	std::cout << "GreedyTeacher" << std::endl;
	std::cout << "Usage: greedy-teacher [OPTION]... [DATA]" << std::endl;
	std::cout << "-h\t\tdisplay this help message" << std::endl;
	std::cout << "-a=TESTS_NO\trun TESTS_NO automatic tests" << std::endl;
	std::cout << "-c=CHILDREN_NO\tspecify number of children for automatic tests" << std::endl;
	std::cout << "-r=MAX_RESULT\tspecify the highest mark that child can get" << std::endl;
}

void Interpreter::RunManualTester()
{
	Tester tester;
	tester.RunManualTests();
}
