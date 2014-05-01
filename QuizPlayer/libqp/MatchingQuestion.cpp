#include "stdafx.h"
#include "MatchingQuestion.h"

using namespace qp;
using namespace std;

CMatchingItems::CMatchingItems(){}
CMatchingItems::~CMatchingItems(){}

void CMatchingItems::AddMatchedItems(string const& leftItem, string const& rightItem)
{
	for (auto it = m_matchedItems.begin(); it < m_matchedItems.end(); ++it)
	{
		if (it->first == leftItem || it->second == rightItem)
		{
			throw invalid_argument("One or both items are already added");
		}
	}
	m_matchedItems.push_back({ leftItem, rightItem });
}

void CMatchingItems::AddExtraItem(string const& extraItem)
{
	if (find(m_extraItems.begin(), m_extraItems.end(), extraItem) != m_extraItems.end())
	{
		throw invalid_argument("Item is already added");
	}
	m_extraItems.push_back(extraItem);
}

size_t CMatchingItems::GetMatchedItemsCount()const
{
	return m_matchedItems.size();
}

size_t CMatchingItems::GetExtraItemsCount()const
{
	return m_extraItems.size();
}

CMatchingItems::MatchedItems const& CMatchingItems::GetMatchedItems(size_t index)const
{
	return m_matchedItems.at(index);
}

string CMatchingItems::GetExtraItem(size_t index)const
{
	return m_extraItems.at(index);
}

vector<string> CMatchingItems::GetLeftMatchedItems()const
{
	vector<string> items;
	for (auto it = m_matchedItems.begin(); it < m_matchedItems.end(); ++it)
	{
		items.push_back(it->first);
	}
	return items;
}

vector<string> CMatchingItems::GetRightMatchedItems()const
{
	vector<string> items;
	for (auto it = m_matchedItems.begin(); it < m_matchedItems.end(); ++it)
	{
		items.push_back(it->second);
	}
	items.insert(items.end(), m_extraItems.begin(), m_extraItems.end());
	return items;
}


CMatchingQuestion::CMatchingQuestion(string const& description, double score)
:CQuestion(description, score)
{
}

CMatchingQuestion::~CMatchingQuestion()
{
}

CMatchingItems const& CMatchingQuestion::GetPairChoices()const
{
	return m_pairChoices;
}

void CMatchingQuestion::SetPairChoices(CMatchingItems const& pairs)
{
	m_pairChoices = pairs;
}