#pragma once

#include "IQuestionView_fwd.h"
#include "types.h"

namespace qp
{

class IQuestionView : public boost::noncopyable
{
public:

	typedef boost::signals2::signal<void()> OnSubmit;
	typedef OnSubmit::slot_type OnSubmitSlotType;

	typedef boost::signals2::signal<void()> OnSkip;
	typedef OnSkip::slot_type OnSkipSlotType;

	typedef boost::signals2::signal<void()> OnNextQuestion;
	typedef OnNextQuestion::slot_type OnNextQuestionSlotType;

	virtual Connection DoOnSubmit(const OnSubmitSlotType & submitHandler) = 0;
	virtual Connection DoOnSkip(const OnSkipSlotType & skipHandler) = 0;
	virtual Connection DoOnNextQuestion(const OnNextQuestionSlotType & nextQuestionHandler) = 0;
	virtual void HandleUserInput() = 0;
	virtual void Show() = 0;
	virtual ~IQuestionView(){}
};

}