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

	typedef boost::signals2::signal<void()> OnExit;
	typedef OnExit::slot_type OnExitSlotType;

	virtual Connection DoOnSubmit(const OnSubmitSlotType & submitHandler) = 0;
	virtual Connection DoOnSkip(const OnSkipSlotType & skipHandler) = 0;
	virtual Connection DoOnExit(const OnExitSlotType & exitHandler) = 0;
	virtual bool HandleUserInput() = 0;
	virtual void Show() = 0;
	virtual ~IQuestionView(){}
};

}