#include "stdafx.h"
#include "Questions.h"

#pragma warning (push)
#pragma warning (disable: 4702)	// Unreachable code

namespace qp
{

using namespace std;

CQuestions::CQuestions()
{
}

size_t CQuestions::GetCount() const
{
	return m_questions.size();
}

void CQuestions::AddQuestion(CQuestionPtr question)
{
	if (find(m_questions.begin(), m_questions.end(), question) == m_questions.end())
	{
		m_questions.push_back(question);
	}
	else
	{
		throw runtime_error("This question is already added");
	}
}

qp::CConstQuestionPtr CQuestions::GetQuestionAtIndex(size_t index) const
{
	if (index >= GetCount())
	{
		throw out_of_range("Index is out of range");
	}
	return m_questions[index];
}

}

#pragma warning (pop)