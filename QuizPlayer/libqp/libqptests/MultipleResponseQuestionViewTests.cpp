#include "stdafx.h"

#include "MultipleResponseQuestion.h"
#include "MultipleResponseQuestionView.h"
#include "MultipleResponseQuestionState.h"

using namespace qp;
using namespace std;

BOOST_AUTO_TEST_SUITE(MultipleResponseQuestionViewTests)

BOOST_AUTO_TEST_CASE(MultipleResponseQuestionViewShowsDescriptionAndDetails)
{
	CGradedChoices choices;
	choices.AddChoice("0 Incorrect", false);
	choices.AddChoice("1 Correct", true);
	choices.AddChoice("2 Incorrect", false);
	choices.AddChoice("3 Correct", true);

	string description = "Description";
	auto question = make_shared<CMultipleResponseQuestion>(description, 10, choices);
	auto state = make_shared<CMultipleResponseQuestionState>(question);
	state->SelectResponse(1);
	state->SelectResponse(3);

	ostringstream ostrm;
	istringstream istrm;
	CMultipleResponseQuestionView view(state, ostrm, istrm);
	view.Show();
	BOOST_CHECK_EQUAL(ostrm.str(), 
		description + "\n"
		"[ ] A. 0 Incorrect\n"
		"[V] B. 1 Correct\n"
		"[ ] C. 2 Incorrect\n"
		"[V] D. 3 Correct\n"
		);

	state->UnselectResponse(3);
	state->Submit();
	view.Show();

	cout << ostrm.str();

/*	BOOST_CHECK_EQUAL(ostrm.str(),
		description + "\n"
		"[ ] A. 0 Incorrect\n"
		"[V] B. 1 Correct\n"
		"[ ] C. 2 Incorrect\n"
		"[V] D. 3 Correct\n"
		);
		*/
	/*
	Description
	1. [ ] Choice 1
	2. [ ] Choice 2
	3. [ ] Choice 3
	*/
	//BOOST_MESSAGE("TODO: verify that choices are shown");
}


BOOST_AUTO_TEST_SUITE_END()