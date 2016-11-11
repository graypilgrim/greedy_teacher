#include "Interpreter.hpp"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <getopt.h>

Interpreter::Interpreter(int argc, char *argv[])
	:argumentsNo(argc), arguments(argv)
{}

void Interpreter::AnalizeCommands()
{
	manualTests = true;
	testsNo = 0;
	pupilsNo = 0;
	maxMark = 0;

	int opt;

	while ((opt = getopt(argumentsNo, arguments, "ha:c:r:")) != EOF)
	{
		switch (opt) {
		case 'h':
			PrintHelp();
			exit(0);

		case 'a':
			manualTests = false;
			testsNo = atol(optarg);
			break;

		case 'c':
			pupilsNo = atol(optarg);
			break;

		case 'r':
			maxMark = atol(optarg);
			break;

		case '?':
			exit(-1);

		default:
			std::cout << std::endl;
			abort();
		}
	}

	if (!manualTests && (testsNo == 0 || pupilsNo == 0 || maxMark == 0))
	{
		std::cout << "If automatic tests are chosen, specify all parameters"<< std::endl;
		std::cout << "Use \"-h\" to see more details" << std::endl;
		exit(-1);
	}

	if (pupilsNo > CHILDREN_LIMIT)
		std::cout << "WARNING: Results may be misleading. Amount of children is too high" << std::endl;
}

void Interpreter::RunTester()
{
	if (manualTests)
	{
		Tester tester;
		tester.RunManualTests();
	}
	else
	{
		Tester tester(testsNo, pupilsNo, maxMark);
		tester.RunAutomaticTests();
	}
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
