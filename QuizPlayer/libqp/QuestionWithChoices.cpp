#include "stdafx.h"
#include "QuestionWithChoices.h"

namespace qp
{
using namespace std;

CGradedChoices::CGradedChoices(const std::initializer_list<GradedChoice> & choices)
:m_choices(choices)
{

}

size_t CGradedChoices::GetChoiceCount() const
{
	return m_choices.size();
}

void CGradedChoices::AddChoice(std::string const & text, bool isCorrect)
{
	if (std::find_if(m_choices.begin(), m_choices.end(), std::bind(std::equal_to<string>(), std::bind(&GradedChoice::text, std::placeholders::_1), text)) != m_choices.end())
	{
		throw(std::invalid_argument("Duplicate choice text"));
	}
	m_choices.push_back({ text, isCorrect });
}

const GradedChoice CGradedChoices::GetChoice(size_t index) const
{
	return m_choices.at(index);
}


CQuestionWithChoices::CQuestionWithChoices(std::string const & description, double score, const CGradedChoices & choices)
:CQuestion(description, score)
,m_choices(choices)
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