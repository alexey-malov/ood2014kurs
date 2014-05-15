// QuizPlayer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "libqp/MultipleChoiceQuestion.h"
#include "libqp/MultipleChoiceQuestionState.h"
#include "libqp/MultipleChoiceQuestionView.h"

#include "libqp/MultipleResponseQuestion.h"
#include "libqp/MultipleResponseQuestionState.h"
#include "libqp/MultipleResponseQuestionView.h"

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

	shared_ptr<IQuestionView> questionView = make_shared<CMultipleChoiceQuestionView>(questionState, cout);
	questionView->Show();
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

	shared_ptr<IQuestionView> questionView = make_shared<CMultipleResponseQuestionView>(questionState, cout);
	questionView->Show();
}

void TestMatchingQuestionVisualization()
{
	// TODO: implement me
}

void TestQuestionVisualization()
{
	cout << "===========Multiple choice question============\n";
	TestMultipleChoiceQuestionVisualization();

	cout << "===========Multiple response question============\n";
	TestMultipleResponseQuestionVisualization();

	cout << "===========Matching question============\n";
	TestMatchingQuestionVisualization();
}

int main()
{
	TestQuestionVisualization();
	
	return 0;
}

