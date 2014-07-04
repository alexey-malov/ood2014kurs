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
	,m_exitRequestConnection(view->DoOnExit(bind(&CQuestionViewController::OnExitRequest, this)))
{
}

CQuestionViewController::~CQuestionViewController()
{
}

bool CQuestionViewController::Run()
{
	m_handleUserInputResult = DEFAULT;
	m_view->Show();
	while (m_handleUserInputResult != EXIT)
	{
		try
		{
			if (m_view->HandleUserInput() && (m_handleUserInputResult == SKIP))
			{
				break;
			}
		}
		catch (exception const&)
		{
		}
	}
	return (m_handleUserInputResult != EXIT);
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

void CQuestionViewController::OnExitRequest()
{
	m_handleUserInputResult = EXIT;
}

}