#pragma once

#include "Question_fwd.h"
#include "IQuestionState.h"

struct CMockQuestionState : public qp::IQuestionState
{
	typedef qp::CConstQuestionPtr QuestionPtrType;

	bool submitted;
	QuestionPtrType question;

	CMockQuestionState(QuestionPtrType const& question)
		:question(question)
		,submitted(false)
	{
	}

	virtual bool Submitted()const final
	{
		return submitted;
	}

	virtual void Submit() override
	{
		submitted = true;
	}

	virtual qp::CConstQuestionPtr GetQuestion() const override
	{
		return question;
	}

};