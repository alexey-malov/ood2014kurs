#pragma once
#include "Question.h"
#include "types.h"
#include <loki/Visitor.h>

namespace qp
{

class CMatchingQuestion : public CQuestion
{
public:
	LOKI_DEFINE_CONST_VISITABLE()

	typedef std::pair<std::string, std::string> MatchedItems;
	typedef std::vector<MatchedItems> MatchedItemsCollection;
	typedef std::vector<std::string> StandaloneItems;

	CMatchingQuestion(const std::string & description, double score = 0.0, const MatchedItemsCollection & matchedItems = MatchedItemsCollection(), const StandaloneItems & extraItems = StandaloneItems());

	const MatchedItemsCollection & GetMatchedItems()const;
	const StandaloneItems & GetExtraItems()const;

	size_t GetMatchedItemsCount()const;
	size_t GetExtraItemsCount()const;

	StandaloneItems GetLeftMatchingItems()const;
	StandaloneItems GetRightMatchingItems()const;

private:
	MatchedItemsCollection m_matchedItems;
	StandaloneItems m_extraItems;
};

}