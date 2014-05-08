#include "stdafx.h"
#include "TypeInQuestion.h"

namespace qp
{

CTypeInQuestion::CTypeInQuestion(std::string const& description, double score)
:CQuestion(description, score)
{
}


CTypeInQuestion::~CTypeInQuestion()
{
}

void CTypeInQuestion::SetAnswers(std::vector<std::string> const& answers) 
{
	m_answers = answers;
}

std::vector<std::string> const& CTypeInQuestion::GetAnswers() const
{
	return m_answers;
}

}