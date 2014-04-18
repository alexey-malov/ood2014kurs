#include "stdafx.h"
#include "Question.h"

namespace qp
{

CQuestion::CQuestion(std::string description)
:m_description(VerifyIfNotEmpty(description))
,m_score(1.0)
,m_correctFeedback("Correct Answer!")
,m_incorrectFeedback("Incorrect Answer!")
{
}

CQuestion::~CQuestion()
{
}

std::string const& CQuestion::GetDescription()const
{
	return m_description;
}

std::string const& CQuestion::GetCorrectFeedback()const
{
	return m_correctFeedback;
}

std::string const& CQuestion::GetIncorrectFeedback()const
{
	return m_incorrectFeedback;
}

double const& CQuestion::GetScore()const
{
	return m_score;
}

std::string CQuestion::VerifyIfNotEmpty(std::string param)
{
	if (param == "")
	{
		throw std::invalid_argument("Empty argument is not allowed");
	}
	return param;
}

}