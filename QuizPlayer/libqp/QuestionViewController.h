#pragma once

#include "IQuestionView_fwd.h"
#include "IQuestionState_fwd.h"
#include "types.h"

namespace qp
{

class CQuestionViewController : public boost::noncopyable
{
public:
	CQuestionViewController(IQuestionStatePtr const& questionState, IQuestionViewPtr const& view);
	virtual ~CQuestionViewController();
private:
	void OnSubmitRequest();
private:
	IQuestionStatePtr const m_questionState;
	IQuestionViewPtr const m_view;

	ScopedConnection m_submitRequestConnection;
};
}
