#pragma once
#include "QuestionViewController.h"

#include "MultipleChoiceQuestionState_fwd.h"
#include "MultipleChoiceQuestionView_fwd.h"

namespace qp
{

class CMultipleChoiceQuestionViewController : public CQuestionViewController
{
public:
	CMultipleChoiceQuestionViewController(IMultipleChoiceQuestionStatePtr const& questionState, CMultipleChoiceQuestionViewPtr const& view);
	~CMultipleChoiceQuestionViewController();
	void OnAnswerSelectedRequest(size_t answerIndex);
private:
	ScopedConnection m_answerSelectedRequestedConnection;
	IMultipleChoiceQuestionStatePtr const m_questionState;
	CMultipleChoiceQuestionViewPtr const m_view;
};

}

