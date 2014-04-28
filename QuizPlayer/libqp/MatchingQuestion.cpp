#include "stdafx.h"
#include "MatchingQuestion.h"

using namespace qp;
using namespace std;

CMatchingPairs::CMatchingPairs(){}
CMatchingPairs::~CMatchingPairs(){}

void CMatchingPairs::AddPair(std::string leftItem, std::string rightItem)
{
	MatchingPair newPair = { leftItem, rightItem };
	m_pairs.push_back(newPair);
}

void CMatchingPairs::AddPair(std::string extraValue)
{
	MatchingPair newPair;
	newPair.rightItem = extraValue;
	m_pairs.push_back(newPair);
}

MatchingPair const & CMatchingPairs::GetMatchingPair(size_t index)const
{
	return m_pairs.at(index);
}

size_t CMatchingPairs::GetPairsCount()const
{
	return m_pairs.size();
}


CMatchingQuestion::CMatchingQuestion(string const& description, double score)
:CQuestion(description, score)
{
}

CMatchingQuestion::~CMatchingQuestion(){}

CMatchingPairs const& CMatchingQuestion::GetPairChoices()const
{
	return m_pairChoices;
}

void CMatchingQuestion::SetPairChoices(CMatchingPairs const& pairs)
{
	m_pairChoices = pairs;
}