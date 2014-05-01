// QuizPlayer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "libqp/MultipleChoiceQuestion.h"
#include "libqp/MultipleChoiceQuestionState.h"
#include "libqp/MultipleChoiceQuestionView.h"

using namespace qp;
using namespace std;


int _tmain()
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
	
	return 0;
}

