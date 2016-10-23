#include "gt.hpp"

GreedyTeacher::GreedyTeacher(uint64_t pupilsNo)
	:this.pupilsNo(pupilsNo)
{
	pupilsMarks.reserve(pupilsNo);
	pupilsCoockies.reserve(pupilsNo);
}

void GreedyTeacher::AddPupil(uint64_t mark)
{
	pupilsMarks.push_back(mark);
}

uint64_t GreedyTeacher::CountCoockies()
{
		uint64_t coockies_no = 0;
		uint64_t firstLocalMin = FindFirstLocalMin();

		for (auto i = firstLocalMin; i > 0; --i)
		{
			if (pupilsMarks[i - 1] > pupilsMarks[i])
				pupilsCoockies[i - 1] = pupilsCoockies[i] + 1;
			else
				pupilsCoockies[i - 1] = pupilsCoockies[i];

			++coockies_no;
		}

		for (auto i = firstLocalMin + 1; i < pupilsNo; ++i)
		{
			if (pupilsMarks[i] > pupilsMarks[i - 1])
				pupilsCoockies[i] = pupilsCoockies[i - 1] + 1;

			if (pupilsMarks[i] < pupilsMarks[i - 1])
				pupilsCoockies[i] = 1;

			if (pupilsMarks[i] == pupilsMarks[i - 1])
				pupilsCoockies[i] = pupilsCoockies[i - 1];

			++coockies_no;
		}

		return coockies_no;
}

uint64_t GreedyTeacher::FindFirstLocalMin()
{
	for (uint64_t i = 1; i < pupilsNo; ++i)
		if (pupilsMarks[i] > pupilsMarks[i - 1])
			return i;

	return 0;
}
