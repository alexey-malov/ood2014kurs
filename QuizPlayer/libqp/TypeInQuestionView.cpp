#include "stdafx.h"
#include "TypeInQuestionView.h"
#include "TypeInQuestionState.h"

using namespace qp;

CTypeInQuestionView::CTypeInQuestionView(CTypeInQuestionStatePtr const& questionState, std::ostream & outputStream)
:CQuestionView(questionState, outputStream)
,m_questionState(questionState)
{
}


CTypeInQuestionView::~CTypeInQuestionView()
{
}
