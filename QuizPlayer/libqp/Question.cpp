#include "stdafx.h"
#include "Question.h"
#include "utils.h"

namespace qp
{

using namespace std;
	

CQuestion::CQuestion(string description, double score)
:m_description(move(VerifyIfNotEmpty(description)))
,m_score(VerifyIfNotNegative(score))
{
}

CQuestion::~CQuestion()
{
}

string const& CQuestion::GetDescription()const
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

void CQuestion::SetCorrectFeedback(string text)
{
	m_correctFeedback = move(text);
}

void CQuestion::SetIncorrectFeedback(string text)
{
	m_incorrectFeedback = move(text);
}

}