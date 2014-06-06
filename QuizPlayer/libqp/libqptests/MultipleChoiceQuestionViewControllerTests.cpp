#include "stdafx.h"

#include "MultipleChoiceQuestionView.h"
#include "MultipleChoiceQuestionState.h"
#include "MultipleChoiceQuestionViewController.h"
#include "MultipleChoiceQuestion.h"

using namespace qp;
using namespace std;

struct MultipleChoiceQuestionViewContollerTestFixture
{
public:
	MultipleChoiceQuestionViewContollerTestFixture()
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

BOOST_FIXTURE_TEST_SUITE(MultipleChoiceQuestionViewControllerTests, MultipleChoiceQuestionViewContollerTestFixture)

BOOST_AUTO_TEST_CASE(ControllerCallsSetUserAnswer)
{
	istringstream istrm("B\n");
	CMultipleChoiceQuestionViewPtr view = make_shared<CMultipleChoiceQuestionView>(state, ostrm, istrm);
	CMultipleChoiceQuestionViewController qvc(state, view);
	
	BOOST_CHECK(!state->GetUserAnswerIndex());
	BOOST_REQUIRE_NO_THROW(view->HandleUserInput());
	BOOST_REQUIRE(state->GetUserAnswerIndex());
	BOOST_CHECK_EQUAL(*state->GetUserAnswerIndex(), 1u);
	
	BOOST_CHECK_EQUAL(ostrm.str(),
		"Choose an answer (A-D) or type 'submit': "
		"What is the name of our planet?\n"
		"( ) A. Mercury\n"
		"(o) B. Venus\n"
		"( ) C. The Earth\n"
		"( ) D. Mars\n"
		);
}

BOOST_AUTO_TEST_CASE(SubmitAndReviewIncorrectAnswer)
{
	istringstream istrm("B\nsubmit\n");
	CMultipleChoiceQuestionViewPtr view = make_shared<CMultipleChoiceQuestionView>(state, ostrm, istrm);
	CMultipleChoiceQuestionViewController qvc(state, view);

	BOOST_REQUIRE_NO_THROW(view->HandleUserInput());
	BOOST_REQUIRE_NO_THROW(view->HandleUserInput());
	BOOST_CHECK_EQUAL(ostrm.str(),
		"Choose an answer (A-D) or type 'submit': "
		"What is the name of our planet?\n"
		"( ) A. Mercury\n"
		"(o) B. Venus\n"
		"( ) C. The Earth\n"
		"( ) D. Mars\n"
		"Choose an answer (A-D) or type 'submit': "
		"What is the name of our planet?\n"
		"  ( ) A. Mercury\n"
		"- (o) B. Venus\n"
		"+ ( ) C. The Earth\n"
		"  ( ) D. Mars\n"
		);
}

BOOST_AUTO_TEST_CASE(SubmitAndReviewCorrectAnswer)
{
	istringstream istrm("C\nsubmit\n");
	CMultipleChoiceQuestionViewPtr view = make_shared<CMultipleChoiceQuestionView>(state, ostrm, istrm);
	CMultipleChoiceQuestionViewController qvc(state, view);

	BOOST_REQUIRE_NO_THROW(view->HandleUserInput());
	BOOST_REQUIRE_NO_THROW(view->HandleUserInput());
	BOOST_CHECK_EQUAL(ostrm.str(),
		"Choose an answer (A-D) or type 'submit': "
		"What is the name of our planet?\n"
		"( ) A. Mercury\n"
		"( ) B. Venus\n"
		"(o) C. The Earth\n"
		"( ) D. Mars\n"
		"Choose an answer (A-D) or type 'submit': "
		"What is the name of our planet?\n"
		"  ( ) A. Mercury\n"
		"  ( ) B. Venus\n"
		"+ (o) C. The Earth\n"
		"  ( ) D. Mars\n"
		);
}

BOOST_AUTO_TEST_SUITE_END()