#include "stdafx.h"

#include "MockQuestionView.h"
#include "MockQuestionState.h"
#include "QuestionViewController.h"
#include "QuestionForTest.h"


using namespace qp;
using namespace std;

struct QuestionViewControllerTestFixture
{
	QuestionViewControllerTestFixture()
	: qs(make_shared<CMockQuestionState>(make_shared<CQuestionForTest>("descr", 10)))
	, qv(make_shared<CMockQuestionView>())
	, qvc(qs, qv)
	{

	}
	shared_ptr<CMockQuestionState> qs;
	shared_ptr<CMockQuestionView> qv;
	CQuestionViewController qvc;
};

BOOST_FIXTURE_TEST_SUITE(QuestionViewControllerTests, QuestionViewControllerTestFixture)

BOOST_AUTO_TEST_CASE(ControllerCallsSubmitOnQuestionStateOnViewSubmit)
{
	BOOST_CHECK(!qs->submitted);
	BOOST_REQUIRE_NO_THROW(qv->onSubmit());
	BOOST_CHECK(qs->submitted);
}

BOOST_AUTO_TEST_CASE(SkippingQuestion)
{
	qv->onHandleUserInput.connect([this](){
		BOOST_REQUIRE_EQUAL(qv->showCallCounter, 1);
		qv->onSkip();
	});
	BOOST_CHECK_NO_THROW(qvc.Run());
	BOOST_CHECK_EQUAL(qv->showCallCounter, 1);
	BOOST_CHECK_EQUAL(qv->handleUserInputCallCounter, 1);
}

BOOST_AUTO_TEST_CASE(SubmittingQuestion)
{
	qv->onHandleUserInput.connect([this](){
		BOOST_CHECK(!qs->submitted);
		BOOST_CHECK_EQUAL(qv->showCallCounter, 1);
		qv->onSubmit();
	});
	BOOST_CHECK_NO_THROW(qvc.Run());
	BOOST_CHECK_EQUAL(qv->showCallCounter, 2);
	BOOST_CHECK_EQUAL(qv->handleUserInputCallCounter, 1);
	BOOST_CHECK(qs->submitted);
}

BOOST_AUTO_TEST_CASE(SkippingSubmittedQuestion)
{
	qv->onHandleUserInput.connect([this](){
		BOOST_CHECK_EQUAL(qv->showCallCounter, 1);
		qv->onNextQuestion();
	});

	qs->submitted = true;
	BOOST_CHECK_NO_THROW(qvc.Run());
	BOOST_CHECK_EQUAL(qv->showCallCounter, 1);
	BOOST_CHECK_EQUAL(qv->handleUserInputCallCounter, 1);
}

BOOST_AUTO_TEST_SUITE_END()