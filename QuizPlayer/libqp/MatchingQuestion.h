#pragma once
#include "Question.h"
#include "types.h"

namespace qp
{

struct MatchingPair
{
	optional_string leftItem;
	optional_string rightItem;
};

class CMatchingPairs
{
public:
	CMatchingPairs();
	~CMatchingPairs();

	void AddPair(std::string leftItem, std::string rightItem); // AddMatchedItems
	void AddPair(std::string extraValue); // AddExtraItem

	// std::vector<std::string> GetLeftMatchedItems()const;
	// std::vector<std::string> GetRightMatchedItems()const;
	// typedef std::pair<std::string, std::string> MatchedItems;
	// size_t GetMatchedItemsCount()const;
	// MatchedItems const& GetMatchedItems(size_t index)const;
	

	MatchingPair const & GetMatchingPair(size_t index)const; // GetMatch
	size_t GetPairsCount()const; // GetMatchesCount

private:
	// std::vector<MatchedItems> m_matchedItems;
	// std::vector<std::string> m_extraItems;
	std::vector<MatchingPair> m_pairs;
};

class CMatchingQuestion : public CQuestion
{
public:
	CMatchingQuestion(std::string const& description, double score = 0.0);
	~CMatchingQuestion();

	CMatchingPairs const& GetPairChoices()const;
	void SetPairChoices(CMatchingPairs const& pairs);

private:
	CMatchingPairs m_pairChoices;
};

}