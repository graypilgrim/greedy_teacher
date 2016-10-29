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

	uint64_t coockiesNo = 0;

	uint64_t rbegin = 0;
	uint64_t rend = 0;
	while (rbegin < pupilsNo)
	{
		rbegin = FindLocalMin(rbegin);
		// std::cout << "Local min: " << rbegin << std::endl;

		if (rbegin == pupilsNo)
			coockiesNo += GiveCoockies(rend);
		else
			coockiesNo += GiveCoockiesReverse(rbegin, rend);

		rend = ++rbegin;
	}

	return coockiesNo;
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

uint64_t GreedyTeacher:: GiveCoockies(uint64_t begin)
{
	// std::cout << "GiveCoockies" << std::endl;
	uint64_t coockies = 0;

	if (begin == 0)
	{
		pupilsCoockies[begin] = 1;
		++begin;
		++coockies;
	}

	for (uint64_t i = begin; i < pupilsNo; ++i)
	{
		if (pupilsMarks[i] > pupilsMarks[i - 1])
			pupilsCoockies[i] = pupilsCoockies[i - 1] + 1;
		else if (pupilsMarks[i] < pupilsMarks[i - 1])
			pupilsCoockies[i] = pupilsCoockies[i - 1] - 1;
		else
			pupilsCoockies[i] = pupilsCoockies[i - 1] ;

		coockies += pupilsCoockies[i];
	}

	return coockies;
}

uint64_t GreedyTeacher::GiveCoockiesReverse(uint64_t rbegin, uint64_t rend)
{
	// std::cout << "GiveCoockiesReverse" << std::endl;
	// std::cout << rbegin << " " << rend << std::endl;

	pupilsCoockies[rbegin] = 1;
	uint64_t coockies = 1;

	if (rbegin == 0)
		return coockies;

	--rbegin;

	// std::cout << rbegin << " " << rend << std::endl;

	while (rbegin >= rend)
	{
		if (pupilsMarks[rbegin] > pupilsMarks[rbegin + 1])
			pupilsCoockies[rbegin] = pupilsCoockies[rbegin + 1] + 1;
		else if (pupilsMarks[rbegin] < pupilsMarks[rbegin + 1])
			pupilsCoockies[rbegin] = pupilsCoockies[rbegin + 1] - 1;
		else
			pupilsCoockies[rbegin] = pupilsCoockies[rbegin + 1];

		coockies += pupilsCoockies[rbegin];

		if (rbegin == 0)
			break;
		else
			--rbegin;
	}

	return coockies;
}

bool GreedyTeacher::VerifyPupilsNo()
{
	if (pupilsMarks.size() != pupilsNo) {
		std::cerr << "Invalid marks number!" << std::endl;
		return false;
	}

	return true;
}
