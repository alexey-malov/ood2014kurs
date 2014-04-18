#include "stdafx.h"
#include "Question.h"
#include "utils.h"

namespace qp
{

CQuestion::CQuestion(std::string description)
:m_description(VerifyIfNotEmpty(description))
,m_score(0.0)
{
}

CQuestion::~CQuestion()
{
}

std::string const& CQuestion::GetDescription()const
{
	return m_description;
}

const optional_string & CQuestion::GetCorrectFeedback()const
{
	return m_correctFeedback;
}

const optional_string & CQuestion::GetIncorrectFeedback()const
{
	return m_incorrectFeedback;
}


double CQuestion::GetScore()const
{
	return m_score;
}

}