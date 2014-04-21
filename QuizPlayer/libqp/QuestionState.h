#pragma once

#include "QuestionState_fwd.h"
#include "Question_fwd.h"

namespace qp
{

class CQuestionState : boost::noncopyable
{
public:
	CQuestionState(CConstQuestionPtr const& question);

	// Indicates whether the question has been submitted (user has givenan  answer to the question)
	bool Submitted()const;

	virtual ~CQuestionState();
private:
	CConstQuestionPtr const m_question;
};

}