#include "stdafx.h"
#include "TypeInQuestion.h"
#include "utils.h"


namespace qp
{

CTypeInQuestion::CTypeInQuestion(std::string const& description, std::set<std::string> const& answers, double score)
:CQuestion(description, score)
{
	for (auto answer : answers)
	{
		std::string answerWithoutExtraSpaces = RemoveExtraSpaces(answer);
		if (answerWithoutExtraSpaces.empty())
		{
			throw std::invalid_argument("Answer cannot be empty");
		}
		m_answers.insert(answerWithoutExtraSpaces);
	}

	if (m_answers.empty())
	{
		throw std::invalid_argument("Answers cannot be empty");
	}
}


CTypeInQuestion::~CTypeInQuestion()
{
}

std::set<std::string> const& CTypeInQuestion::GetAnswers() const
{
	return m_answers;
}

}