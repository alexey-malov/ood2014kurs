#include "stdafx.h"
#include "QuestionViewController.h"
#include "IQuestionState.h"
#include "IQuestionView.h"

namespace qp
{

using namespace std;

CQuestionViewController::CQuestionViewController(IQuestionStatePtr const& questionState, IQuestionViewPtr const& view)
	: m_questionState(questionState)
	, m_view(view)
	, m_submitRequestConnection(view->SubmitRequested().connect(bind(&CQuestionViewController::OnSubmitRequest, this)))
{
}


CQuestionViewController::~CQuestionViewController()
{

}

void CQuestionViewController::OnSubmitRequest()
{
	m_questionState->Submit();
}

}