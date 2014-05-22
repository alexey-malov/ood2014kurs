#include "stdafx.h"
#include "SequenceQuestion.h"

using namespace qp;
using namespace std;
using MatchedItems = CSequenceQuestion::MatchedItems;

CSequenceQuestion::CSequenceQuestion(const string & description, double score, const MatchedItems & matchedItems)
:CQuestion(description, score)
{
	if (matchedItems.size() < 3)
	{
		throw invalid_argument("minimum 3 matching items required");
	}

	bool emptyAnswerExists = (find(matchedItems.begin(), matchedItems.end(), "") != matchedItems.end());
	if (emptyAnswerExists)
	{
		throw invalid_argument("matching item cannot be empty");
	}

	set<string> uniqueItems(matchedItems.begin(), matchedItems.end());
	if (uniqueItems.size() != matchedItems.size())
	{
		throw invalid_argument("matching items contain duplicates");
	}

	m_matchedItems = matchedItems;
}

const MatchedItems & CSequenceQuestion::GetMatchedItems()const
{
	return m_matchedItems;
}