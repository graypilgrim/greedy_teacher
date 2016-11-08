#include "GreedyTeacher.hpp"

GreedyTeacher::GreedyTeacher(size_t pupilsNo)
	:pupilsNo(pupilsNo), calculated(false)
{
	pupilsMarks.reserve(pupilsNo);
	pupilsCoockies.reserve(pupilsNo);
}

void GreedyTeacher::AddPupil(size_t mark)
{
	pupilsMarks.push_back(mark);
	pupilsCoockies.push_back(0);
}

void GreedyTeacher::CountCoockies()
{
	if (!VerifyPupilsNo())
		return;

	long coockiesNo = 0;

	size_t rbegin = 0;
	size_t rend = 0;
	while (rbegin < pupilsNo)
	{
		rbegin = FindLocalMin(rbegin);

		if (rbegin == pupilsNo)
			coockiesNo += GiveCoockies(rend);
		else
			coockiesNo += GiveCoockiesReverse(rbegin, rend);

		rend = ++rbegin;
	}

	calculated = true;
	coockies = coockiesNo;
}

size_t GreedyTeacher::GetCoockies()
{
	if (calculated)
		return coockies;

	CountCoockies();
	return coockies;
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

size_t GreedyTeacher::FindLocalMin(size_t begin)
{
	if (begin == 0 && pupilsMarks[begin] < pupilsMarks[begin + 1])
		return begin;

	for (size_t i = begin; i < pupilsNo; ++i)
		if (pupilsMarks[i] < pupilsMarks[i + 1] && pupilsMarks[i] <= pupilsMarks[i - 1])
			return i;

	return pupilsNo;
}

size_t GreedyTeacher:: GiveCoockies(size_t begin)
{
	long coockies = 0;

	if (begin == 0)
	{
		pupilsCoockies[begin] = 1;
		++begin;
		++coockies;
	}

	for (size_t i = begin; i < pupilsNo; ++i)
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

size_t GreedyTeacher::GiveCoockiesReverse(size_t rbegin, size_t rend)
{
	pupilsCoockies[rbegin] = 1;
	long coockies = 1;

	if (rbegin == 0)
		return coockies;

	--rbegin;

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
