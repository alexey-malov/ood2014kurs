#include "stdafx.h"
#include "MultipleChoiceQuestionViewController.h"
#include "MultipleChoiceQuestionState.h"
#include "MultipleChoiceQuestionView.h"

namespace qp
{

CMultipleChoiceQuestionViewController::CMultipleChoiceQuestionViewController(IMultipleChoiceQuestionStatePtr const& questionState, CMultipleChoiceQuestionViewPtr const& view)
:CQuestionViewController(questionState, view)
,m_questionState(questionState)
,m_view(view)
,m_answerSelectedRequestedConnection(view->DoOnAnswerSelected(bind(&CMultipleChoiceQuestionViewController::OnAnswerSelectedRequest, this, _1)))
{
}

CMultipleChoiceQuestionViewController::~CMultipleChoiceQuestionViewController()
{
}

void CMultipleChoiceQuestionViewController::OnAnswerSelectedRequest(size_t answerIndex)
{
	m_questionState->SetUserAnswerIndex(answerIndex);
	m_view->Show();
}

}