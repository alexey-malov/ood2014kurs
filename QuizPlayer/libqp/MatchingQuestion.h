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

	void AddPair(std::string leftItem, std::string rightItem);
	void AddPair(std::string extraValue);
	MatchingPair const & GetMatchingPair(size_t index)const;
	size_t GetPairsCount()const;

private:
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