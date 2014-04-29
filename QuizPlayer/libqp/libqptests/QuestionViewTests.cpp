#include "stdafx.h"

#include "Question.h"
#include "QuestionState.h"
#include "QuestionView.h"
#include "QuestionStateForTesting.h"

using namespace qp;
using namespace std;

BOOST_AUTO_TEST_SUITE(QuestionViewTests)

BOOST_AUTO_TEST_CASE(QuestionViewShowsDescriptionAndDetails)
{
	string description = "Description";
	auto question = make_shared<CQuestion>(description, 10);
	auto state = make_shared<CQuestionStateForTesting>(question);
	
	ostringstream ostrm;
	CQuestionView view(state, ostrm);
	view.Show();
	BOOST_CHECK_EQUAL(ostrm.str(), description + "\n");
}


BOOST_AUTO_TEST_SUITE_END()