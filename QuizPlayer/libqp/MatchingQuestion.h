#pragma once
#include "Question.h"
#include "types.h"

namespace qp
{

class CMatchingItems
{
public:
	CMatchingItems();
	~CMatchingItems();
	
	typedef std::pair<std::string, std::string> MatchedItems;
	size_t GetMatchedItemsCount()const;
	size_t GetExtraItemsCount()const;
	MatchedItems const& GetMatchedItems(size_t index)const;
	std::string const& GetExtraItem(size_t index)const;

	void AddMatchedItems(std::string const& leftItem, std::string const& rightItem);
	void AddExtraItem(std::string const& extraItem);

	std::vector<std::string> GetLeftMatchedItems()const;
	std::vector<std::string> GetRightMatchedItems()const;
	
private:
	std::vector<MatchedItems> m_matchedItems;
	std::vector<std::string> m_extraItems;
};


class CMatchingQuestion : public CQuestion
{
public:
	LOKI_DEFINE_CONST_VISITABLE()

	CMatchingQuestion(std::string const& description, double score = 0.0);
	~CMatchingQuestion();

	CMatchingItems const& GetPairChoices()const;
	void SetPairChoices(CMatchingItems const& pairs);

private:
	CMatchingItems m_pairChoices;
};

}