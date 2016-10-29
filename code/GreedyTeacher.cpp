#include "GreedyTeacher.hpp"

GreedyTeacher::GreedyTeacher(uint64_t pupilsNo)
	:pupilsNo(pupilsNo)
{
	pupilsMarks.reserve(pupilsNo);
	pupilsCoockies.reserve(pupilsNo);
}

void GreedyTeacher::AddPupil(uint64_t mark)
{
	pupilsMarks.push_back(mark);
	pupilsCoockies.push_back(0);
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
		std::cout << "Local min: " << it << std::endl;

		++it;
	}

	return coockies_no;
}

void GreedyTeacher::PrintMarks()
{
	if (!VerifyPupilsNo())
		return;

	for (auto it : pupilsMarks)
		std::cout << it << " ";

	std::cout << std::endl;
}

void GreedyTeacher::PrintCoockies()
{
	if (!VerifyPupilsNo())
		return;

	for (auto it : pupilsCoockies)
		std::cout << it << " ";

	std::cout << std::endl;
}

uint64_t GreedyTeacher::FindLocalMin(uint64_t begin)
{
	if (begin == 0 && pupilsMarks[begin] < pupilsMarks[begin + 1])
		return begin;

	for (uint64_t i = begin; i < pupilsNo; ++i)
		if (pupilsMarks[i] < pupilsMarks[i + 1] && pupilsMarks[i] < pupilsMarks[i - 1])
			return i;

	return pupilsNo;
}

bool GreedyTeacher::VerifyPupilsNo()
{
	if (pupilsMarks.size() != pupilsNo) {
		std::cerr << "Invalid marks number!" << std::endl;
		return false;
	}

	return true;
}
