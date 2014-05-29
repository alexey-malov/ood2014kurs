#include "stdafx.h"
#include "QuestionStates.h"
#include "QuestionStateImpl.h"
#include "Question.h"
#include "QuestionForTest.h"

using namespace qp;
using namespace std;

struct QuestionStateTestsFixture
{
	QuestionStateTestsFixture()
	:question(make_shared<CQuestionForTest>("Question", 10))
	{
	}

	CQuestionPtr question;
};

BOOST_FIXTURE_TEST_SUITE(QuestionStatesTestSuite, QuestionStateTestsFixture)

class CQuestionStateForTesting : public CQuestionState
{
public:
	CQuestionStateForTesting(CConstQuestionPtr const& question)
		:CQuestionState(question)
		, doSubmitCallCounter(0)
	{
	}

	int doSubmitCallCounter;

protected:
	void DoSubmit()override
	{
		++doSubmitCallCounter;
	}
};

BOOST_AUTO_TEST_CASE(QuestionStatesCollectionIsInitiallyEmpty)
{
	CQuestionStates questionStates;
	BOOST_CHECK_EQUAL(questionStates.GetCount(), 0u);
}

BOOST_AUTO_TEST_CASE(QuestionStateCanBeAddedToCollectionAndAccessed)
{
	CQuestionStates questionStates;
	auto questionState = make_shared<CQuestionStateForTesting>(question);
	questionStates.AddQuestionState(questionState);
	BOOST_CHECK_EQUAL(questionStates.GetCount(), 1u);
	BOOST_CHECK_EQUAL(questionStates.GetQuestionStateAtIndex(0), questionState);

	//check index out of range
	BOOST_CHECK_THROW(questionStates.GetQuestionStateAtIndex(1), out_of_range);
}

BOOST_AUTO_TEST_CASE(SameQuestionStatesAreNotAdded)
{
	CQuestionStates questionStates;
	auto questionState = make_shared<CQuestionStateForTesting>(question);
	questionStates.AddQuestionState(questionState);
	BOOST_CHECK_THROW(questionStates.AddQuestionState(questionState), runtime_error);
	BOOST_CHECK_EQUAL(questionStates.GetCount(), 1u);
	BOOST_CHECK_EQUAL(questionStates.GetQuestionStateAtIndex(0), questionState);
}

BOOST_AUTO_TEST_CASE(DifferentQuestionStatesCanBeAdded)
{
	//states sre different, but they refer to one question - error?
	CQuestionStates questionStates;
	auto questionState = make_shared<CQuestionStateForTesting>(question);
	auto questionState1 = make_shared<CQuestionStateForTesting>(question);
	questionStates.AddQuestionState(questionState);
	questionStates.AddQuestionState(questionState1);
	BOOST_CHECK_EQUAL(questionStates.GetCount(), 2u);
	BOOST_CHECK_EQUAL(questionStates.GetQuestionStateAtIndex(0), questionState);
	BOOST_CHECK_EQUAL(questionStates.GetQuestionStateAtIndex(1), questionState1);
}

BOOST_AUTO_TEST_SUITE_END()
