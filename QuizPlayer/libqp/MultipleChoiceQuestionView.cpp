#include "stdafx.h"
#include "MultipleChoiceQuestionView.h"
#include "MultipleChoiceQuestionState.h"


namespace qp
{

CMultipleChoiceQuestionView::CMultipleChoiceQuestionView(const CMultipleChoiceQuestionStatePtr & questionState, std::ostream & outputStream)
:CQuestionView(questionState, outputStream)
,m_questionState(questionState)
{
}


CMultipleChoiceQuestionView::~CMultipleChoiceQuestionView()
{
}

void CMultipleChoiceQuestionView::ShowDetails() const
{
}

}