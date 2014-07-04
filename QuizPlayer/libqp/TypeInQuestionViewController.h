#pragma once
#include "QuestionViewController.h"
#include "TypeInQuestionState_fwd.h"
#include "TypeInQuestionView_fwd.h"

namespace qp
{

class CTypeInQuestionViewController : public CQuestionViewController
{
public:
	CTypeInQuestionViewController(CTypeInQuestionStatePtr const& state, CTypeInQuestionViewPtr const& view);
	~CTypeInQuestionViewController();
	void OnAnswerEnteredRequest(std::string const& answer);
private:
	ScopedConnection m_answerEnteredRequestedConnection;
	CTypeInQuestionStatePtr const m_state;
	CTypeInQuestionViewPtr const m_view;
};

}
