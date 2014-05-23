#include "stdafx.h"

#include "MockQuestionView.h"
#include "MockQuestionState.h"
#include "QuestionViewController.h"

using namespace qp;
using namespace std;

BOOST_AUTO_TEST_SUITE(QuestionViewControllerTests)


BOOST_AUTO_TEST_CASE(ControllerCallsSubmitOnQuestionStateOnViewSubmit)
{
	auto qs = make_shared<CMockQuestionState>();
	auto qv = make_shared<CMockQuestionView>();

	CQuestionViewController qvc(qs, qv);
	BOOST_CHECK(!qs->submitted);
	BOOST_REQUIRE_NO_THROW(qv->onSubmit());
	BOOST_CHECK(qs->submitted);
}

BOOST_AUTO_TEST_SUITE_END()