#pragma once
#include "IQuestionView.h"

struct CMockQuestionView : public qp::IQuestionView
{
public:
	CMockQuestionView()
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
		skipHandler;
		throw std::logic_error("The method or operation is not implemented.");
	}

	virtual void HandleUserInput()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	virtual void Show()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	OnSubmit onSubmit;
};

