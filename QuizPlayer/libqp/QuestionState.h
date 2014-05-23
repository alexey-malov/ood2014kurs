#pragma once

#include "QuestionState_fwd.h"
#include "Question_fwd.h"

#include "IQuestionState.h"

namespace qp
{

class CQuestionState : public IQuestionState
{
public:
	CQuestionState(CConstQuestionPtr const& question);

	CConstQuestionPtr GetQuestion()const;

	// Indicates whether the question has been submitted (user has given an  answer to the question)
	bool Submitted()const;

	void Submit() override final;

	virtual ~CQuestionState();
protected:
	virtual void DoSubmit() = 0;
private:
	bool m_submitted;
	CConstQuestionPtr const m_question;
};

}