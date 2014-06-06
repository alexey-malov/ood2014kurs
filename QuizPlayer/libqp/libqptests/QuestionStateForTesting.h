#pragma once

#include "QuestionStateImpl.h"

class CQuestionStateForTesting : public qp::CQuestionState
{
public:
	CQuestionStateForTesting(qp::CConstQuestionPtr const& question)
		:qp::CQuestionState(question)
		,doSubmitCallCounter(0)
	{
	}

	int doSubmitCallCounter;

protected:
	void DoSubmit()override
	{
		++doSubmitCallCounter;
	}
};


