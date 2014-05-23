#pragma once

#include "IQuestionState.h"

struct CMockQuestionState : public qp::IQuestionState
{
	bool submitted;

	CMockQuestionState()
		:submitted(false)
	{
	}

	virtual void Submit()
	{
		submitted = true;
	}

};