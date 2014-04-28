#include "stdafx.h"
#include "SequenceQuestion.h"

namespace qp
{


CSequenceQuestion::CSequenceQuestion(std::string const &description, double score /*= 0.0*/)
	:CQuestion(description, score)
{
}


CSequenceQuestion::~CSequenceQuestion()
{
}

void CSequenceQuestion::AddChoice(std::string const & text, size_t id)
{
	SequenceChoice choice = {id, text};
	m_choices.push_back(choice);
}

void CSequenceQuestion::AddOrderId(size_t id)
{
	m_order.push_back(id);
}

std::vector<SequenceChoice> const & CSequenceQuestion::GetChoices() const
{
	return m_choices;
}

std::vector<size_t> const& CSequenceQuestion::GetOrder() const
{
	return m_order;
}

size_t CSequenceQuestion::GetChoiceCount() const
{
	return m_choices.size();
}


}