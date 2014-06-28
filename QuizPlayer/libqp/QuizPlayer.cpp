#include "stdafx.h"
#include "QuizPlayer.h"
#include "IQuizView.h"
#include "QuizSession.h"
#include "QuestionStates.h"
#include "Quiz.h"
#include "QuestionStateFactory.h"
#include "IQuestionState.h"
#include "SessionController.h"

namespace qp
{

using namespace std;

CQuizPlayer::CQuizPlayer(CConstQuizPtr const& quiz, IQuizView & view)
:m_quiz(quiz)
,m_quizView(view)
{

}


CQuizPlayer::~CQuizPlayer(void)
{
}

void CQuizPlayer::Start()
{
	auto session = CreateNewSession();
	CSessionController controller(session);
	controller.Run();
}

CQuizSessionPtr CQuizPlayer::CreateNewSession()const
{
	CQuestionStateFactory stateFactory;
	auto questions = m_quiz->GetQuestions();
	CQuestionStates states;
	for (size_t i = 0; i < questions.GetCount(); ++i)
	{
		auto question = questions.GetQuestionAtIndex(i);
		IQuestionStatePtr questionState(stateFactory.CreateStateForQuestion(question));
		states.AddQuestionState(questionState);
	}
	auto session = make_shared<CQuizSession>(m_quiz, states);
	return session;
}

}