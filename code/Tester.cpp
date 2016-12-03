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
		GreedyTeacher gtBrute(pupilsNo);

		size_t mark;
		for (size_t j = 0; j < pupilsNo; ++j)
		{
			std::cin >> mark;
			gt.AddPupil(mark);
			gtBrute.AddPupil(mark);
		}

		std::cout << "Dynamic algorithm: " << std::endl;
		auto solvingTime = MeasureSolvingTime(gt);
		PrintFormatedResult(gt, solvingTime, i);
		gt.PrintCoockies();

		std::cout << "Brute algorithm: " << std::endl;
		gtBrute.CountCoockiesBrute();
		gtBrute.PrintCoockies();
	}
}

void Tester::RunAutomaticTests()
{
	srand(time(NULL));

	std::cout << "Automatic tests suite\n" << std::endl;

	long long testsSumTime = 0;
	for (size_t i = 0; i < testsNo; ++i)
	{
		long randDelta = CalculateDelta();
		size_t pupilsNo = testSize + randDelta;
		GreedyTeacher gt(pupilsNo);
		GreedyTeacher gtBrute(pupilsNo);

		for (size_t j = 0; j < pupilsNo; ++j)
		{
			size_t mark = rand() % maxMark + 1;
			std::cout << mark << " ";
			gt.AddPupil(mark);
			gtBrute.AddPupil(mark);
		}
		std::cout << std::endl;

		auto solvingTime = MeasureSolvingTime(gt);
		testsSumTime += solvingTime;
		PrintFormatedResult(gt, solvingTime, i);
		gt.PrintCoockies();

		gtBrute.CountCoockiesBrute();
		gtBrute.PrintCoockies();
	}

	std::cout << "Test suite mean time: " << testsSumTime/testsNo << std::endl;
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

void Tester::PrintFormatedResult(GreedyTeacher &gt, long solvingTime, size_t testNo)
{
	std::cout << ">>Test " << testNo;
	std::cout << "\tTest size: " << gt.GetPupilsNo();
	std::cout << "\tResult: " << gt.GetCoockies();
	std::cout << "\tSolving time: " << solvingTime  << " us" << std::endl;
}
