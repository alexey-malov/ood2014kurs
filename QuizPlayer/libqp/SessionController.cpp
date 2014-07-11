#include "stdafx.h"
#include "SessionController.h"
#include "QuestionView.h"
#include "QuestionViewController.h"
#include "QuizSession.h"

#include "MultipleChoiceQuestionState.h"
#include "MultipleChoiceQuestionView.h"
#include "MultipleChoiceQuestionViewController.h"

namespace qp
{
using namespace std;

CSessionController::CSessionController(CQuizSessionPtr const& session)
: m_session(session)
, m_viewControllerFactory(&cout, &cin)
{
}

CSessionController::~CSessionController()
{
}

void CSessionController::Run()
{
	bool exit = false;
	while (!exit)
	{
		IQuestionStatePtr state = m_session->GetCurrentQuestionState();
		auto controller = m_viewControllerFactory.CreateViewControllerForState(state);
		if (!(controller->Run()))
		{
			break;
		}
		m_session->GotoNextQuestion();
	}
}

}