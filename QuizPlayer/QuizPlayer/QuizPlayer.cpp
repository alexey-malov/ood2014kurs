// QuizPlayer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "libqp/MultipleChoiceQuestion.h"
#include "libqp/MultipleChoiceQuestionState.h"
#include "libqp/MultipleChoiceQuestionView.h"
#include "libqp/MultipleChoiceQuestionViewController.h"

#include "libqp/MultipleResponseQuestion.h"
#include "libqp/MultipleResponseQuestionState.h"
#include "libqp/MultipleResponseQuestionView.h"

#include "libqp/MatchingQuestion.h"
#include "libqp/MatchingQuestionState.h"
#include "libqp/MatchingQuestionView.h"

#include "libqp/QuestionViewFactory.h"
#include "libqp/QuestionStateFactory.h"

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

	auto questionState = make_shared<CMultipleChoiceQuestionState>(question);

	auto questionView = make_shared<CMultipleChoiceQuestionView>(questionState, cout, cin);
	auto controller = make_shared<CMultipleChoiceQuestionViewController>(questionState, questionView);
	controller->Run();
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

	shared_ptr<IQuestionView> questionView = make_shared<CMultipleResponseQuestionView>(questionState, cout, cin);
	questionView->Show();
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
	cout << "\n===========Multiple choice question============\n";
	TestMultipleChoiceQuestionVisualization();

	cout << "\n===========Multiple response question============\n";
	TestMultipleResponseQuestionVisualization();

	cout << "\n===========Matching question============\n";
	TestMatchingQuestionVisualization();
}

int main()
{
	CQuestionStateFactory stateFactory;
	CQuestionViewFactory viewFactory(&cout, &cin);
	
	CConstMultipleChoiceQuestionPtr multipleChoiceQuestionPtr(new CMultipleChoiceQuestion("MultipleChoiceQuestion description", 0.0, CGradedChoices{ { "one", "two" } }));
	IQuestionStatePtr mcqStatePtr = stateFactory.CreateStateForQuestion(multipleChoiceQuestionPtr);
	auto mcqVieqPtr = viewFactory.CreateView(mcqStatePtr);
	dynamic_cast<CMultipleChoiceQuestionView*>(mcqVieqPtr.get());
	return 0;
//	TestQuestionVisualization();
	
	//return 0;
}

