#pragma once

#include "IQuestionView_fwd.h"

namespace qp
{

class IQuestionView : public boost::noncopyable
{
public:
	typedef boost::signals2::signal<void()> SubmitRequestedSignal;
	typedef boost::signals2::signal<void()> SkipRequestedSignal;

	virtual SubmitRequestedSignal & SubmitRequested() = 0;
	virtual SkipRequestedSignal & SkipRequested() = 0;
	virtual void HandleUserInput() = 0;
	virtual void Show() = 0;
	virtual ~IQuestionView(){}
};

}