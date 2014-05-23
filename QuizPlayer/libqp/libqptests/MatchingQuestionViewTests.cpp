#include "stdafx.h"

#include "MatchingQuestion.h"
#include "MatchingQuestionView.h"
#include "MatchingQuestionState.h"

using namespace qp;
using namespace std;

BOOST_AUTO_TEST_SUITE(MatchingQuestionViewTests)

BOOST_AUTO_TEST_CASE(MatchingQuestionViewShowsDescriptionAndDetails)
{
	string description = "Match countries with its capitols:";
	CMatchingQuestion::MatchedItemsCollection matchedItems = {
		CMatchingQuestion::MatchedItems("Germany", "Berlin"),
		CMatchingQuestion::MatchedItems("Spain", "Madrid"),
		CMatchingQuestion::MatchedItems("France", "Paris")
	};
	CMatchingQuestion::StandaloneItems extraItems = { "Moscow", "Peking" };
	CConstMatchingQuestionPtr question = make_shared<CMatchingQuestion>(description, 20, matchedItems, extraItems);

	auto questionState = make_shared<CMatchingQuestionState>(question, false);
	
	ostringstream ostrm;
	istringstream istrm;
	shared_ptr<IQuestionView> questionView = make_shared<CMatchingQuestionView>(questionState, ostrm, istrm);
	questionView->Show();
	BOOST_CHECK_EQUAL(ostrm.str(), description + "\n"
		"1. Germany     A. Berlin\n"
		"2. Spain       B. Madrid\n"
		"3. France      C. Paris\n"
		"               D. Moscow\n"
		"               E. Peking\n");
}

BOOST_AUTO_TEST_SUITE_END()