#include "stdafx.h"
#include "MultipleResponseQuestionView.h"
#include "MultipleResponseQuestionState.h"


namespace qp
{

CMultipleResponseQuestionView::CMultipleResponseQuestionView(const CMultipleResponseQuestionStatePtr & questionState, std::ostream & outputStream)
:CQuestionView(questionState, outputStream)
,m_questionState(questionState)
{
}


CMultipleResponseQuestionView::~CMultipleResponseQuestionView()
{
}

void CMultipleResponseQuestionView::ShowDetails()
{
}

}