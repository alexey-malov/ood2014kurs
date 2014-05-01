#include "stdafx.h"
#include "QuizSession.h"
#include "QuestionStates.h"

namespace qp
{

using namespace std;

CQuizSession::CQuizSession(CConstQuizPtr const& quiz, const CQuestionStates & questionStates)
:m_questionStates(questionStates)
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

}