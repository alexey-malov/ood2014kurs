#pragma once

namespace qp
{

class IQuestionView : public boost::noncopyable
{
public:
	typedef boost::signals2::signal<void()> SubmitRequestedSignal;
	virtual SubmitRequestedSignal & SubmitRequested() = 0;
	virtual void HandleUserInput() = 0;
	virtual void Show() = 0;
	virtual ~IQuestionView(){}
};

}