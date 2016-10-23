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
		uint64_t index;
		uint64_t firstLocalMin;

		for (uint64_t i = 1; i < pupilsNo; ++i)
			if (pupilsMarks[i] > pupilsMarks[i - 1])
			{
				firstLocalMin = i;
				pupilsMarks[i] = 1;
				coockies_no += 1;
			}

		do
		{
			static i = firstLocalMin - 1;
			if (pupilsMarks[i] > pupilsMarks[i + 1])
				pupilsMarks[i] = pupilsMarks[i + 1] + 1;
			else
				pupilsMarks[i] = pupilsMarks[i + 1];
		} while (i-- > 0);


		return coockies_no;
}
