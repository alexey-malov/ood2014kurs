#pragma once
#include "Question.h"
#include <vector>


namespace qp
{

struct SequenceChoice
{
	size_t id;
	std::string text;
};


class CSequenceQuestion : public CQuestion
{
public:
	CSequenceQuestion(std::string const &description, double score = 0.0);
	virtual ~CSequenceQuestion();
	void AddChoice(std::string const & text, size_t id);
	void AddOrderId(size_t id);
	size_t GetChoiceCount()const;
	std::vector<SequenceChoice> const & GetChoices() const;
	std::vector<size_t> const& GetOrder() const;
private:
	std::vector<SequenceChoice> m_choices;
	std::vector<size_t> m_order;
};

}