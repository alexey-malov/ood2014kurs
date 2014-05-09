#include "stdafx.h"
#include "TypeInQuestion.h"

namespace qp
{

CTypeInQuestion::CTypeInQuestion(std::string const& description, std::set<std::string> const& answers, double score)
:CQuestion(description, score)
{
	if (answers.empty())
	{
		throw std::invalid_argument("Answer cannot be empty");
	}
	m_answers = answers;
}


CTypeInQuestion::~CTypeInQuestion()
{
}

std::set<std::string> const& CTypeInQuestion::GetAnswers() const
{
	return m_answers;
}

}