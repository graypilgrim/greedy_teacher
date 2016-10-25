#include "gt.hpp"

GreedyTeacher::GreedyTeacher(uint64_t pupilsNo)
	:pupilsNo(pupilsNo)
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
	if (!VerifyPupilsNo())
		return 0;

	uint64_t coockies_no = 0;

	uint64_t it = 0;
	while (it < pupilsNo)
	{
		it = FindLocalMin(it);
		pupilsCoockies[it] = 1;
		coockies_no += 1;

		for (uint64_t i = it; i > 0; --i)
		{
			if (pupilsMarks[i - 1] > pupilsMarks[i])
				pupilsCoockies[i - 1] = pupilsCoockies[i] + 1;
			else
				pupilsCoockies[i - 1] = pupilsCoockies[i];

			coockies_no += pupilsCoockies[i - 1];
		}

		++it;
	}

	return coockies_no;
}

void GreedyTeacher::PrintMarks()
{
	if (!VerifyPupilsNo())
		return;

	for (auto it : pupilsMarks)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void GreedyTeacher::PrintCoockies()
{
	if (!VerifyPupilsNo())
		return;

	for (auto it : pupilsCoockies)
		std::cout << *it << " ";
	std::cout << std::endl;
}

uint64_t GreedyTeacher::FindLocalMin(uint64_t begin)
{
	for (uint64_t i = begin; i < pupilsNo; ++i)
		if (pupilsMarks[i] > pupilsMarks[i - 1])
			return i;

	return pupilsNo - 1;
}

bool GreedyTeacher::VerifyPupilsNo()
{
	if (pupilsMarks.size() != pupilsNo)
		std::cerr << "Invalid marks number!" << std::endl;
		return false;
	}

	return true;
}
