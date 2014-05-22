#include "stdafx.h"

#include "MultipleResponseQuestion.h"
#include "MultipleResponseQuestionView.h"
#include "MultipleResponseQuestionState.h"

using namespace qp;
using namespace std;

BOOST_AUTO_TEST_SUITE(MultipleResponseQuestionViewTests)

BOOST_AUTO_TEST_CASE(MultipleResponseQuestionViewShowsDescriptionAndDetails)
{
	string description = "Description";
	auto question = make_shared<CMultipleResponseQuestion>(description, 10);
	auto state = make_shared<CMultipleResponseQuestionState>(question);
	
	ostringstream ostrm;
	istringstream istrm;
	CMultipleResponseQuestionView view(state, ostrm, istrm);
	view.Show();
	BOOST_CHECK_EQUAL(ostrm.str(), description + "\n");
	/*
	Description
	1. [ ] Choice 1
	2. [ ] Choice 2
	3. [ ] Choice 3
	*/
	BOOST_MESSAGE("TODO: verify that choices are shown");
}


BOOST_AUTO_TEST_SUITE_END()