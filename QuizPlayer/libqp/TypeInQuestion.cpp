#include "stdafx.h"
#include "TypeInQuestion.h"

namespace qp
{

CTypeInQuestion::CTypeInQuestion(std::string const& description, std::set<std::string> const& answers, double score)
:CQuestion(description, score)
{
	m_answers.clear();
	
	for (auto answer : answers)
	{
		std::string answerWithoutExtraSpaces = RemoveExtraSpaces(answer);
		if (answerWithoutExtraSpaces == "")
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

std::string RemoveExtraSpaces(std::string const& arg)
{
	std::string::const_iterator it = arg.begin();
	std::string newStr;
	while (it != arg.end())
	{
		while (it != arg.end() && *it == ' ')
		{
			++it;
		}
		if (it != arg.end() && !newStr.empty())
		{
			newStr += ' ';
		}
		while (it != arg.end() && *it != ' ')
		{
			newStr += *it;
			++it;
		}
	}
	return newStr;
}

}