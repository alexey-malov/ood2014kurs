#pragma once

#include "Quiz_fwd.h"
#include "QuizSession_fwd.h"
#include "QuestionStates.h"

namespace qp
{

class CQuizSession : boost::noncopyable
{
public:
	CQuizSession(CConstQuizPtr const& quiz, const CQuestionStates & questionStates);
	~CQuizSession();

	IQuestionStatePtr GetCurrentQuestionState()const;
	void GotoNextQuestion();

	const CQuestionStates & GetQuestionStates()const;
private:
	CQuestionStates m_questionStates;
	size_t m_currentQuestionIndex;
};

}