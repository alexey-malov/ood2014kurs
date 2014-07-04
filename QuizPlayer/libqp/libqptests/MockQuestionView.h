#pragma once
#include "IQuestionView.h"

struct CMockQuestionView : public qp::IQuestionView
{
public:
	CMockQuestionView()
	:showCallCounter(0)
	,handleUserInputCallCounter(0)
	{
	}

	~CMockQuestionView()
	{
	}

	virtual qp::Connection DoOnSubmit(const OnSubmitSlotType & submitHandler) override
	{
		return onSubmit.connect(submitHandler);
	}

	virtual qp::Connection DoOnSkip(const OnSkipSlotType & skipHandler) override
	{
		return onSkip.connect(skipHandler);
	}

	virtual qp::Connection DoOnExit(const OnExitSlotType & exitHandler) override
	{
		return onExit.connect(exitHandler);
	}

	virtual bool HandleUserInput()
	{
		++handleUserInputCallCounter;
		onHandleUserInput();
		return true;
	}

	virtual void Show()
	{
		++showCallCounter;
	}
	
	int showCallCounter;
	int handleUserInputCallCounter;

	typedef boost::signals2::signal<void()> OnHandleUserInput;
	
	OnHandleUserInput onHandleUserInput;

	OnSubmit onSubmit;
	OnSkip onSkip;
	OnExit onExit;
};

