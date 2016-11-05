#include "Tester.hpp"

Tester::Tester()
	:testsNo(0), testsSize(0)
{}

Tester::Tester(size_t size, size_t amount)
	:testsNo(amount), testsSize(size)
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

		size_t input;

		for (size_t j = 0; j < pupilsNo; ++j)
		{
			std::cin >> input;
			gt.AddPupil(input);
		}

		auto elapsedTime = MeasureSolvingTime(gt);
		std::cout << "Execute time: " << elapsedTime  << "us" << std::endl;
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
