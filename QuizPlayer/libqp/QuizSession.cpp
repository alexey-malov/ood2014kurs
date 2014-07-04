#include "stdafx.h"
#include "QuizSession.h"
#include "QuestionStates.h"

namespace qp
{

using namespace std;

CQuizSession::CQuizSession(CConstQuizPtr const& quiz, const CQuestionStates & questionStates)
:m_questionStates(questionStates)
,m_currentQuestionIndex(0)
{
	quiz;
	questionStates;
}


CQuizSession::~CQuizSession()
{
}

const CQuestionStates & CQuizSession::GetQuestionStates()const
{
	return m_questionStates;
}

qp::IQuestionStatePtr CQuizSession::GetCurrentQuestionState() const
{
	return m_questionStates.GetQuestionStateAtIndex(m_currentQuestionIndex);
}

void CQuizSession::GotoNextQuestion()
{
	m_currentQuestionIndex = (m_currentQuestionIndex + 1) % m_questionStates.GetCount();
}

}