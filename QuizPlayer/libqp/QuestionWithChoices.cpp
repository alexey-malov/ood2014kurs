#include "stdafx.h"
#include "QuestionWithChoices.h"
#include "boost/bind.hpp"

namespace qp
{
using namespace std;

size_t CGradedChoices::GetChoiceCount() const
{
	return m_choices.size();
}

void CGradedChoices::AddChoice(std::string const & text, bool isCorrect)
{
	if (std::find_if(m_choices.begin(), m_choices.end(), boost::bind(&GradedChoice::text, _1) == text) != m_choices.end())
	{
		throw(std::invalid_argument("Duplicate choice text"));
	}
	m_choices.push_back({ text, isCorrect });
}

const GradedChoice CGradedChoices::GetChoice(size_t index) const
{
	return m_choices.at(index);
}



CQuestionWithChoices::CQuestionWithChoices(std::string const & description, double score)
:CQuestion(description, score)
{
}

CQuestionWithChoices::~CQuestionWithChoices()
{
}

CGradedChoices const& CQuestionWithChoices::GetChoices() const
{
	return m_choices;
}

void CQuestionWithChoices::SetChoices(CGradedChoices const& choices)
{
	m_choices = choices;
}


}