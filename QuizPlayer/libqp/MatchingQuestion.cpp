#include "stdafx.h"
#include "MatchingQuestion.h"
#include <set>

using namespace qp;
using namespace std;
using MatchedItems = CMatchingQuestion::MatchedItems;
using StandaloneItems = CMatchingQuestion::StandaloneItems;

CMatchingQuestion::CMatchingQuestion(const string& description, double score, const MatchedItemsCollection & matchedItems, const StandaloneItems & extraItems)
:CQuestion(description, score)
{
	
	set<string> leftItems, rightItems;
	transform(matchedItems.begin(), matchedItems.end(), inserter(leftItems, leftItems.begin()), [](MatchedItems pairItems){ return pairItems.first; });
	transform(matchedItems.begin(), matchedItems.end(), inserter(rightItems, rightItems.begin()), [](MatchedItems pairItems){ return pairItems.second; });
	rightItems.insert(extraItems.begin(), extraItems.end());
	if (leftItems.size() != matchedItems.size() || rightItems.size() != matchedItems.size() + extraItems.size())
	{
		throw invalid_argument("Duplicates in matching question are not allowed");
	}
	
	m_matchedItems = matchedItems;
	m_extraItems = extraItems;
}

const CMatchingQuestion::MatchedItemsCollection & CMatchingQuestion::GetMatchedItems()const
{
	return m_matchedItems;
}

const StandaloneItems & CMatchingQuestion::GetExtraItems()const
{
	return m_extraItems;
}

StandaloneItems CMatchingQuestion::GetLeftMatchingItems()const
{
	StandaloneItems items;
	items.reserve(m_matchedItems.size());
	transform(m_matchedItems.begin(), m_matchedItems.end(), back_inserter(items), [](MatchedItems pairItems){ return pairItems.first; });
	return items;
}

StandaloneItems CMatchingQuestion::GetRightMatchingItems()const
{
	StandaloneItems items;
	items.reserve(m_matchedItems.size() + m_extraItems.size());
	transform(m_matchedItems.begin(), m_matchedItems.end(), back_inserter(items), [](MatchedItems pairItems){ return pairItems.second; });
	items.insert(items.end(), m_extraItems.begin(), m_extraItems.end());
	return items;
}

size_t CMatchingQuestion::GetMatchedItemsCount()const
{
	return m_matchedItems.size();
}

size_t CMatchingQuestion::GetExtraItemsCount()const
{
	return m_extraItems.size();
}

size_t CMatchingQuestion::GetLeftMatchingItemsCount()const
{
	return GetLeftMatchingItems().size();
}

size_t CMatchingQuestion::GetRightMatchingItemsCount()const
{
	return GetRightMatchingItems().size();
}