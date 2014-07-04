#pragma once
#include "QuestionViewController.h"
#include "MultipleResponseQuestionState_fwd.h"
#include "MultipleResponseQuestionView_fwd.h"

namespace qp
{

class CMultipleResponseQuestionViewController : public CQuestionViewController
{
public:
	CMultipleResponseQuestionViewController(CMultipleResponseQuestionStatePtr const& questionState, CMultipleResponseQuestionViewPtr const& view);
	~CMultipleResponseQuestionViewController();
	void OnChoiceSelectedRequest(size_t answerIndex);
private:
	ScopedConnection m_choiceSelectedRequestedConnection;
	CMultipleResponseQuestionStatePtr const m_questionState;
	CMultipleResponseQuestionViewPtr const m_view;
};

}

