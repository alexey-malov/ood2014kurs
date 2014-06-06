#include "stdafx.h"
#include "SequenceQuestion.h"
#include "SequenceQuestionState.h"
#include "QuestionReview.h"


using namespace qp;
using namespace std;
using Sequence = CSequenceQuestion::Sequence;

Sequence sequence = { "one", "two", "three", "four" };

struct SequenceQuestionStateTestsFixture
{
	SequenceQuestionStateTestsFixture()
	:question(make_shared<CSequenceQuestion>("Question", 1, sequence))
	{
	}

	CConstSequenceQuestionPtr question;
};

BOOST_FIXTURE_TEST_SUITE(SequenceQuestionStateTests, SequenceQuestionStateTestsFixture)

BOOST_AUTO_TEST_CASE(Construction)
{
	CSequenceQuestionState state(question);
	Sequence emptySequence = {};
	BOOST_REQUIRE_EQUAL_COLLECTIONS(state.GetAnswer().begin(), state.GetAnswer().end(), emptySequence.begin(), emptySequence.end());
}

BOOST_AUTO_TEST_CASE(SettingAnswer)
{
	CSequenceQuestionState state(question);
	Sequence answer = { "one", "two", "three" };
	state.SetAnswer(answer);
	BOOST_REQUIRE_EQUAL_COLLECTIONS(state.GetAnswer().begin(), state.GetAnswer().end(), answer.begin(), answer.end());
}

BOOST_AUTO_TEST_SUITE_END()
