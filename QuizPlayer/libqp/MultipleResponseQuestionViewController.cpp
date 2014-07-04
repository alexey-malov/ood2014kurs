#include "stdafx.h"
#include "MultipleResponseQuestionViewController.h"
#include "MultipleResponseQuestionState.h"
#include "MultipleResponseQuestionView.h"

namespace qp
{

CMultipleResponseQuestionViewController::CMultipleResponseQuestionViewController(CMultipleResponseQuestionStatePtr const& questionState, CMultipleResponseQuestionViewPtr const& view)
:CQuestionViewController(questionState, view)
, m_questionState(questionState)
, m_view(view)
, m_choiceSelectedRequestedConnection(view->DoOnChoiceSelected(bind(&CMultipleResponseQuestionViewController::OnChoiceSelectedRequest, this, _1)))
{

}

CMultipleResponseQuestionViewController::~CMultipleResponseQuestionViewController()
{

}

void CMultipleResponseQuestionViewController::OnChoiceSelectedRequest(size_t answerIndex)
{
	bool isSelected = m_questionState->ResponseIsSelected(answerIndex);
	m_questionState->ChangeResponse(answerIndex, !isSelected);
	m_view->Show();
}

}
