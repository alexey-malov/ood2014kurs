#include "stdafx.h"
#include "MatchingQuestion.h"

using namespace qp;
using namespace std;

CMatchingItems::CMatchingItems(){}
CMatchingItems::~CMatchingItems(){}

void CMatchingItems::AddMatchedItems(string const& leftItem, string const& rightItem)
{
	if (any_of(m_matchedItems.begin(), m_matchedItems.end(), 
		[leftItem, rightItem](MatchedItems items){ return (items.first == leftItem || items.second == rightItem); }))
	{
		throw invalid_argument("One or both items are already added");
	}
	if (any_of(m_extraItems.begin(), m_extraItems.end(), [rightItem](string const& item){ return item == rightItem; }))
	{
		throw invalid_argument("Right item already exists in extra items");
	}
	m_matchedItems.push_back({ leftItem, rightItem });
}

void CMatchingItems::AddExtraItem(string const& extraItem)
{
	if (any_of(m_extraItems.begin(), m_extraItems.end(), [extraItem](string const& item){ return item == extraItem; }))
	{
		throw invalid_argument("Item is already added");
	}
	if (any_of(m_matchedItems.begin(), m_matchedItems.end(), [extraItem](MatchedItems items){ return items.second == extraItem; }))
	{
		throw invalid_argument("Item is already exists as right item in matched items");
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

string const& CMatchingItems::GetExtraItem(size_t index)const
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