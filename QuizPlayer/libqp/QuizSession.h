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

	const CQuestionStates & GetQuestionStates()const;
private:
	CQuestionStates m_questionStates;
};

}