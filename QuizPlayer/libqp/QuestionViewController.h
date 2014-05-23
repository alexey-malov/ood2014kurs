#pragma once

#include "IQuestionView_fwd.h"
#include "IQuestionState_fwd.h"

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

	boost::signals2::scoped_connection m_submitRequestConnection;
};
}
