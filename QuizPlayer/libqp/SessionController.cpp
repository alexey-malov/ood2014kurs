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
:m_session(session)
{
}

CSessionController::~CSessionController()
{
}

CMultipleChoiceQuestionViewControllerPtr CSessionController::CreateMultipleChoiceQuestionViewController(IQuestionStatePtr state)
{
	auto mcState = dynamic_pointer_cast<CMultipleChoiceQuestionState>(state);
	auto view = make_shared<CMultipleChoiceQuestionView>(mcState, cout, cin);
	auto controller = make_shared<CMultipleChoiceQuestionViewController>(mcState, view);
	return controller;
}

void CSessionController::Run()
{
	bool exit = false;
	while (!exit)
	{
		cout << "\n**Before state\n";
		IQuestionStatePtr state = m_session->GetCurrentQuestionState();
		cout << "**Before function\n";
		auto controller = CreateMultipleChoiceQuestionViewController(state);
		
		if (controller->Run())
		{
			break;
		}
		m_session->GotoNextQuestion();
	}
}

}