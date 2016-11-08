#include "Tester.hpp"

Tester::Tester()
	:testsNo(0), testSize(0), maxMark(0)
{}

Tester::Tester(size_t suiteSize, size_t childrenNo, size_t maxResult)
	:testsNo(suiteSize), testSize(childrenNo), maxMark(maxResult)
{}

void Tester::RunManualTests()
{
	size_t testsNo;
	std::cin >> testsNo;

	for (size_t i = 0; i < testsNo; ++i)
	{
		size_t pupilsNo;
		std::cin >> pupilsNo;

		GreedyTeacher gt(pupilsNo);

		size_t mark;
		for (size_t j = 0; j < pupilsNo; ++j)
		{
			std::cin >> mark;
			gt.AddPupil(mark);
		}

		auto solvingTime = MeasureSolvingTime(gt);
		std::cout << "Test size: " << pupilsNo << std::endl;
		std::cout << "Result: " << gt.GetCoockies() << std::endl;
		std::cout << "Solving time: " << solvingTime << "\n" << std::endl;

		 gt.PrintMarks();
		 gt.PrintCoockies();
	}
}

void Tester::RunAutomaticTests()
{
	srand(time(NULL));

	std::cout << "Automatic tests suite\n" << std::endl;

	for (size_t i = 0; i < testsNo; ++i)
	{
		long randDelta = CalculateDelta();
		size_t pupilsNo = testSize + randDelta;
		GreedyTeacher gt(pupilsNo);

		for (size_t j = 0; j < pupilsNo; ++j)
		{
			size_t mark = rand() % maxMark + 1;
			gt.AddPupil(mark);
		}

		auto solvingTime = MeasureSolvingTime(gt);
		std::cout << ">>Test " << i << std::endl;
		std::cout << "Test size: " << pupilsNo << std::endl;
		std::cout << "Result: " << gt.GetCoockies() << std::endl;
		std::cout << "Solving time: " << solvingTime << "\n" << std::endl;

		 gt.PrintMarks();
		 gt.PrintCoockies();
	}
}

long Tester::MeasureSolvingTime(GreedyTeacher &gt)
{
	using namespace std::chrono;
	high_resolution_clock::time_point begin = high_resolution_clock::now();
	gt.CountCoockies();
	high_resolution_clock::time_point end = high_resolution_clock::now();

	return duration_cast<microseconds>(end - begin).count();
}

long Tester::CalculateDelta()
{
	if (testSize == 1)
		return 0;

	if (testSize < 10)
		return 1;

	long changeRange = testSize / 10;
	long delta = (rand() % changeRange) - (changeRange / 2);

	return delta;
}
