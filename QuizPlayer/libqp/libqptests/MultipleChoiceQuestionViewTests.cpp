#include "stdafx.h"

#include "MultipleChoiceQuestion.h"
#include "MultipleChoiceQuestionView.h"
#include "MultipleChoiceQuestionState.h"

using namespace qp;
using namespace std;

BOOST_AUTO_TEST_SUITE(MultipleChoiceQuestionViewTests)

BOOST_AUTO_TEST_CASE(MultipleChoiceQuestionViewShowsDescriptionAndDetails)
{
	string description = "What is the name of our planet ?";
	auto question = make_shared<CMultipleChoiceQuestion>(description, 10, CGradedChoices({
		{ "Mercury", false },
		{ "Venus", false },
		{ "The Earth", true },
		{ "Mars", false }
	}));

	auto questionState = make_shared<CMultipleChoiceQuestionState>(question);
	ostringstream ostrm;
	istringstream istrm;
	shared_ptr<IQuestionView> questionView = make_shared<CMultipleChoiceQuestionView>(questionState, ostrm, istrm);
	questionView->Show();
	BOOST_CHECK_EQUAL(ostrm.str(), 
		description + "\n"
		"A. Mercury\n"
		"B. Venus\n"
		"C. The Earth\n"
		"D. Mars\n"
		"Choose an answer (A-D) or type 'submit': "
		);
}

BOOST_AUTO_TEST_SUITE_END()