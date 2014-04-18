#include "stdafx.h"
#include "Question.h"
#include "utils.h"

namespace qp
{

using namespace std;
	

CQuestion::CQuestion(string description)
:m_description(move(VerifyIfNotEmpty(description)))
,m_score(0.0)
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

void CQuestion::SetCorrectFeedback(string feedback)
{
	m_correctFeedback = move(feedback);
}

void CQuestion::SetIncorrectFeedback(std::string text)
{
	throw logic_error("Not implemented");
}



}