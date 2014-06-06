#pragma once

#include "IQuestionView_fwd.h"
#include "QuestionState_fwd.h"
#include "types.h"

namespace qp
{

class CQuestionViewController : public boost::noncopyable
{
public:
	CQuestionViewController(IQuestionStatePtr const& questionState, IQuestionViewPtr const& view);
	virtual ~CQuestionViewController();
	void Run();
protected:
	enum UserInput { DEFAULT, SUBMIT, SKIP };
private:
	void OnSubmitRequest();
	void OnSkipRequest();

	ScopedConnection m_submitRequestConnection;
	ScopedConnection m_skipRequestConnection;
	
	IQuestionStatePtr const m_questionState;
	IQuestionViewPtr const m_view;
	UserInput m_handleUserInputResult;
	
};
}
