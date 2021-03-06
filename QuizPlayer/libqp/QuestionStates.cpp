#include "stdafx.h"
#include "QuestionStates.h"

using namespace qp;
using namespace std;

CQuestionStates::CQuestionStates()
{
}


CQuestionStates::~CQuestionStates()
{
}

size_t CQuestionStates::GetCount()const
{
	return m_questionStates.size();
}

void qp::CQuestionStates::AddQuestionState(IQuestionStatePtr const& questionState)
{
	if (find(m_questionStates.begin(), m_questionStates.end(), questionState) == m_questionStates.end())
	{
		m_questionStates.push_back(questionState);
	}
	else
	{
		throw runtime_error("This question state is already added");
	}
}

IQuestionStatePtr CQuestionStates::GetQuestionStateAtIndex(size_t index)const
{
	if (index >= GetCount())
	{
		throw out_of_range("Index is out of range");
	}
	return m_questionStates[index];
}
