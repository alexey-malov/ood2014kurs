#include "stdafx.h"
#include "TypeInQuestionViewController.h"
#include "TypeInQuestionState.h"
#include "TypeInQuestionView.h"

namespace qp
{

CTypeInQuestionViewController::CTypeInQuestionViewController(CTypeInQuestionStatePtr const& state, CTypeInQuestionViewPtr const& view)
:CQuestionViewController(state, view)
,m_state(state)
,m_view(view)
,m_answerEnteredRequestedConnection(view->DoOnAnswerEntered(bind(&CTypeInQuestionViewController::OnAnswerEnteredRequest, this, _1)))
{
}

CTypeInQuestionViewController::~CTypeInQuestionViewController()
{
}

void CTypeInQuestionViewController::OnAnswerEnteredRequest(std::string const& answer)
{
	m_state->SetUserAnswer(answer);
	m_view->Show();
}

}