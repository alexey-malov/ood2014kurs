// QuizPlayer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "libqp/Questions.h"
#include "libqp/QuestionStates.h"
#include "libqp/Quiz.h"
#include "libqp/QuizSession.h"
#include "libqp/SessionController.h"

#include "libqp/MultipleChoiceQuestion.h"
#include "libqp/MultipleChoiceQuestionState.h"
#include "libqp/MultipleChoiceQuestionView.h"
#include "libqp/MultipleChoiceQuestionViewController.h"

#include "libqp/MultipleResponseQuestion.h"
#include "libqp/MultipleResponseQuestionState.h"
#include "libqp/MultipleResponseQuestionView.h"
#include "libqp/MultipleResponseQuestionViewController.h"

#include "libqp/MatchingQuestion.h"
#include "libqp/MatchingQuestionState.h"
#include "libqp/MatchingQuestionView.h"

using namespace qp;
using namespace std;

void TestMultipleChoiceQuestionVisualization()
{
	auto question = make_shared<CMultipleChoiceQuestion>("What is the name of our planet?", 10, CGradedChoices({
		{ "Mercury", false },
		{ "Venus", false },
		{ "The Earth", true },
		{ "Mars", false }
	}));

	auto question1 = make_shared<CMultipleChoiceQuestion>("Choose correct answer", 5, CGradedChoices({
		{ "Incorrect", false },
		{ "Correct", true },
		{ "Wrong answer", false },
		{ "Mistake", false }
	}));

	auto questionState = make_shared<CMultipleChoiceQuestionState>(question);
	auto questionState1 = make_shared<CMultipleChoiceQuestionState>(question1);

	auto questionView = make_shared<CMultipleChoiceQuestionView>(questionState, cout, cin);
	auto controller = make_shared<CMultipleChoiceQuestionViewController>(questionState, questionView);

	CQuestions questions;
	questions.AddQuestion(question);
	questions.AddQuestion(question1);
	
	CQuestionStates states;
	states.AddQuestionState(questionState);
	states.AddQuestionState(questionState1);

	auto quiz = make_shared<CQuiz>("Quiz name");
	quiz->SetQuestions(questions);
	auto session = make_shared<CQuizSession>(quiz, states);
	CSessionController sessionController(session);
	sessionController.Run();
}

void TestMultipleResponseQuestionVisualization()
{
	auto question = make_shared<CMultipleResponseQuestion>("Prime numbers:", 10, CGradedChoices({
		{ "2", true },
		{ "3", true },
		{ "4", false },
		{ "5", true }
	}));

	auto questionState = make_shared<CMultipleResponseQuestionState>(question);

	auto questionView = make_shared<CMultipleResponseQuestionView>(questionState, cout, cin);
	auto controller = make_shared<CMultipleResponseQuestionViewController>(questionState, questionView);
	controller->Run();
}

void TestMatchingQuestionVisualization()
{
	CMatchingQuestion::MatchedItemsCollection matchedItems = {
		CMatchingQuestion::MatchedItems("Germany", "Berlin"),
		CMatchingQuestion::MatchedItems("Spain", "Madrid"),
		CMatchingQuestion::MatchedItems("France", "Paris")
	};
	CMatchingQuestion::StandaloneItems extraItems = { "Moscow", "Peking" };
	CConstMatchingQuestionPtr question = make_shared<CMatchingQuestion>("Match countries with its capitols:", 20, matchedItems, extraItems);

	auto questionState = make_shared<CMatchingQuestionState>(question);

	shared_ptr<IQuestionView> questionView = make_shared<CMatchingQuestionView>(questionState, cout, cin);
	questionView->Show();
}

void TestQuestionVisualization()
{
	cout << "\n===========Multiple choice questions quiz==========\n";
	TestMultipleChoiceQuestionVisualization();
	
	cout << "\n\n===========Multiple response question============\n";
	TestMultipleResponseQuestionVisualization();

	cout << "\n===========Matching question============\n";
	TestMatchingQuestionVisualization();
	
}

int main()
{
	TestQuestionVisualization();
	
	return 0;
}

