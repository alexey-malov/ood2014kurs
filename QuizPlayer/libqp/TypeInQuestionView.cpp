#include "stdafx.h"
#include "TypeInQuestionView.h"
#include "TypeInQuestionState.h"

using namespace qp;

CTypeInQuestionView::CTypeInQuestionView(CTypeInQuestionStatePtr const& questionState, std::ostream & outputStream, std::istream & inputStream)
:CQuestionView(questionState, outputStream, inputStream)
,m_questionState(questionState)
{
}


CTypeInQuestionView::~CTypeInQuestionView()
{
}

void CTypeInQuestionView::ShowDetails()
{
}