#include "stdafx.h"

#include "MultipleChoiceQuestion.h"
#include "MultipleChoiceQuestionView.h"
#include "MultipleChoiceQuestionState.h"

using namespace qp;
using namespace std;

struct MultipleChoiceQuestionViewTestFixture
{
public:
	MultipleChoiceQuestionViewTestFixture()
	:state(make_shared<CMultipleChoiceQuestionState>(make_shared<CMultipleChoiceQuestion>("What is the name of our planet?", 10, CGradedChoices({
			{ "Mercury", false },
			{ "Venus", false },
			{ "The Earth", true },
			{ "Mars", false }
	}))))
	{}
	
	CMultipleChoiceQuestionStatePtr state;
	ostringstream ostrm;
};

BOOST_FIXTURE_TEST_SUITE(MultipleChoiceQuestionViewTests, MultipleChoiceQuestionViewTestFixture)

BOOST_AUTO_TEST_CASE(MultipleChoiceQuestionViewShowsDescriptionAndDetails)
{
	istringstream istrm("A");
	shared_ptr<IQuestionView> questionView = make_shared<CMultipleChoiceQuestionView>(state, ostrm, istrm);
	questionView->Show();
	BOOST_CHECK_EQUAL(ostrm.str(), 
		"What is the name of our planet?\n"
		"A. Mercury\n"
		"B. Venus\n"
		"C. The Earth\n"
		"D. Mars\n"
		"Choose an answer (A-D) or type 'submit': "
		);
	BOOST_REQUIRE_NO_THROW(questionView->HandleUserInput());
}

BOOST_AUTO_TEST_CASE(LettersAreConsideredToBeUserChoices)
{
	ostringstream ostrm;
	istringstream istrm;
	//shared_ptr<IQuestionView> questionView = make_shared<CMultipleChoiceQuestionView>(questionState, ostrm, istrm);
}

BOOST_AUTO_TEST_SUITE_END()