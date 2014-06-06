#include "stdafx.h"
#include "QuestionViewController.h"
#include "IQuestionState.h"
#include "IQuestionView.h"

namespace qp
{
using namespace std;

CQuestionViewController::CQuestionViewController(IQuestionStatePtr const& questionState, IQuestionViewPtr const& view)
	:m_questionState(questionState)
	,m_view(view)
	,m_handleUserInputResult(DEFAULT)
	,m_submitRequestConnection(view->DoOnSubmit(bind(&CQuestionViewController::OnSubmitRequest, this)))
	,m_skipRequestConnection(view->DoOnSkip(bind(&CQuestionViewController::OnSkipRequest, this)))
{
}

CQuestionViewController::~CQuestionViewController()
{
}

void CQuestionViewController::Run()
{
	m_view->Show();
	while (m_handleUserInputResult != SUBMIT)
	{
		if (m_view->HandleUserInput() && (m_handleUserInputResult == SKIP))
		{
			break;
		}
	}
	m_handleUserInputResult = DEFAULT;
}

void CQuestionViewController::OnSubmitRequest()
{
	m_questionState->Submit();
	m_view->Show();
	m_handleUserInputResult = SUBMIT;
}

void CQuestionViewController::OnSkipRequest()
{
	m_handleUserInputResult = SKIP;
}

}