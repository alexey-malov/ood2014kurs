#include "stdafx.h"

#include "MultipleResponseQuestion.h"
#include "MultipleResponseQuestionState.h"
#include "QuestionReview.h"

using namespace qp;
using namespace std;

struct MultipleResponseQuestionStateTestFixture
{
	MultipleResponseQuestionStateTestFixture()
	:question(make_shared<CMultipleResponseQuestion>("Question description", 10))
	{
		CGradedChoices choices;
		choices.AddChoice("0 Incorrect", false);
		choices.AddChoice("1 Correct", true);
		choices.AddChoice("2 Incorrect", false);
		choices.AddChoice("3 Correct", true);
		question->SetChoices(choices);
	}

	CMultipleResponseQuestionPtr question;
};

BOOST_FIXTURE_TEST_SUITE(MultipleResponseQuestionStateTests, MultipleResponseQuestionStateTestFixture)


BOOST_AUTO_TEST_CASE(ResponseIsOutOfRange)
{
	CMultipleResponseQuestionState state(question);
	BOOST_REQUIRE_NO_THROW(state.SelectResponse(1));
	BOOST_REQUIRE_THROW(state.SelectResponse(100), out_of_range);
}

// TODO: http://www.boost.org/doc/libs/1_55_0/libs/test/doc/html/utf/user-guide/test-organization/manual-nullary-test-case.html
void VerifyReview(CMultipleResponseQuestionState &questionState, double expectedScore, bool isCorrect)
{
	BOOST_REQUIRE_NO_THROW(questionState.Submit());
	BOOST_REQUIRE_NO_THROW(questionState.GetReview());
	auto review = questionState.GetReview();
	BOOST_CHECK(review.AnswerIsCorrect() == isCorrect);
	BOOST_CHECK_EQUAL(review.GetAwardedScore(), expectedScore);
}

BOOST_AUTO_TEST_CASE(SubmittingCorrectAnswer)
{
	CMultipleResponseQuestionState state(question);
	state.SelectResponse(1);
	state.SelectResponse(3);
	BOOST_REQUIRE_NO_THROW(VerifyReview(state, 10.0, true));
}

BOOST_AUTO_TEST_CASE(SubmittingIncorrectAnswer)
{
	CMultipleResponseQuestionState state(question);
	state.SelectResponse(3);
	BOOST_REQUIRE_NO_THROW(VerifyReview(state, 0.0, false));
}


BOOST_AUTO_TEST_CASE(ForbidChangingAnswerAfterSubmit)
{
	CMultipleResponseQuestionState state(question);
	state.SelectResponse(3);
	state.Submit();
	BOOST_REQUIRE_THROW(state.UnselectResponse(3), logic_error);
	BOOST_CHECK_EQUAL(state.ResponseIsSelected(3), true);
}

BOOST_AUTO_TEST_SUITE_END()
