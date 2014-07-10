#include "stdafx.h"

#include "TypeInQuestionView.h"
#include "TypeInQuestionState.h"
#include "TypeInQuestionViewController.h"
#include "TypeInQuestion.h"

using namespace qp;
using namespace std;

set<string> answers = { "First answer", "Second answer" };

struct TypeInQuestionViewControllerFixture
{
	TypeInQuestionViewControllerFixture()
	:state(make_shared<CTypeInQuestionState>(make_shared<CTypeInQuestion>("Question description", answers, 10)))
	{
	}
	CTypeInQuestionStatePtr state;
	ostringstream ostrm;
};

BOOST_FIXTURE_TEST_SUITE(TypeInQuestionViewTests, TypeInQuestionViewControllerFixture)

BOOST_AUTO_TEST_CASE(ControllerCallsSetUserAnswer)
{
	istringstream istrm("answer\n");
	CTypeInQuestionViewPtr view = make_shared<CTypeInQuestionView>(state, ostrm, istrm);
	CTypeInQuestionViewController qvc(state, view);

	BOOST_CHECK(state->GetUserAnswer().empty());
	BOOST_REQUIRE(view->HandleUserInput());
	BOOST_CHECK_EQUAL(state->GetUserAnswer(), "answer");
	BOOST_CHECK_EQUAL(ostrm.str(),"Enter an answer or type 'submit' or 'skip': "
								   "Question description\n"
								   "Your answer: 'answer'\n");
}

BOOST_AUTO_TEST_CASE(SubmitAndReviewAnswer)
{
	istringstream istrm("answer\nsubmit\n");
	CTypeInQuestionViewPtr view = make_shared<CTypeInQuestionView>(state, ostrm, istrm);
	CTypeInQuestionViewController qvc(state, view);

	BOOST_REQUIRE(view->HandleUserInput());
	BOOST_REQUIRE(view->HandleUserInput());
	BOOST_CHECK_EQUAL(ostrm.str(), "Enter an answer or type 'submit' or 'skip': "
		"Question description\n"
		"Your answer: 'answer'\n"
		"Enter an answer or type 'submit' or 'skip': "
		"Question description\n"
		"Your answer: 'answer'\n"
		"Right answer(s): 'First answer'\n"
		"'Second answer'\n"
		"Answer is not correct."
		);
}

BOOST_AUTO_TEST_SUITE_END()