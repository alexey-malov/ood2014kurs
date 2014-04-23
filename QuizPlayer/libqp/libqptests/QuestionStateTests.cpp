#include "stdafx.h"

#include "QuestionState.h"
#include "Question.h"

using namespace qp;
using namespace std;

struct QuestionStateTestsFixture
{
	QuestionStateTestsFixture()
	:question(make_shared<CQuestion>("Question", 10))
	{
	}

	CQuestionPtr question;
};


BOOST_FIXTURE_TEST_SUITE(QuestionStateTests, QuestionStateTestsFixture)

class CQuestionStateForTesting : public qp::CQuestionState
{
public:
	CQuestionStateForTesting(CConstQuestionPtr const& question)
		:CQuestionState(question)
		,doSubmitCallCounter(0)
	{
	}

	int doSubmitCallCounter;

protected:
	void DoSubmit()override
	{
		++doSubmitCallCounter;
	}
};


BOOST_AUTO_TEST_CASE(InitialQuestionState)
{
	BOOST_CHECK_THROW((CQuestionStateForTesting(nullptr)), invalid_argument);
	CQuestionStateForTesting questionState(question);
	BOOST_CHECK(!questionState.Submitted());
}

BOOST_AUTO_TEST_CASE(QuestionCanBeSubmittedOnlyOnce)
{
	CQuestionStateForTesting questionState(question);
	BOOST_CHECK_NO_THROW(questionState.Submit());
	BOOST_CHECK(questionState.Submitted());
	BOOST_CHECK_EQUAL(questionState.doSubmitCallCounter, 1);

	//try to submit again
	BOOST_CHECK_THROW(questionState.Submit(), logic_error);
	BOOST_CHECK_EQUAL(questionState.doSubmitCallCounter, 1);
}

BOOST_AUTO_TEST_SUITE_END()
