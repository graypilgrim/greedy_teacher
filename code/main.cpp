#include <iostream>
#include "GreedyTeacher.hpp"
#include "Tester.hpp"

int main()
{
	size_t testsNo;
	std::cin >> testsNo;

	for (size_t i = 0; i < testsNo; ++i)
	{
		size_t pupilsNo;
		std::cin >> pupilsNo;

		GreedyTeacher gt = GreedyTeacher(pupilsNo);

		uint64_t input;

		for (size_t j = 0; j < pupilsNo; ++j)
		{
			std::cin >> input;
			gt.AddPupil(input);
		}

		std::cout << gt.CountCoockies() << std::endl;
		gt.PrintMarks();
		gt.PrintCoockies();
	}
}
