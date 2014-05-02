#include "stdafx.h"

#include "MultipleChoiceQuestion.h"
#include "MultipleChoiceQuestionState.h"
#include "QuestionReview.h"

using namespace qp;
using namespace std;

struct MultipleChoiceQuestionStateTestFixture
{
	MultipleChoiceQuestionStateTestFixture()
	:question(make_shared<CMultipleChoiceQuestion>("Question description", 10))
	{
		CGradedChoices choices;
		choices.AddChoice("Incorrect", false);
		choices.AddChoice("Correct", true);
		choices.AddChoice("Incorrect too", false);
		question->SetChoices(choices);
	}

	CMultipleChoiceQuestionPtr question;
};

BOOST_FIXTURE_TEST_SUITE(MultipleChoiceQuestionStateTests, MultipleChoiceQuestionStateTestFixture)


BOOST_AUTO_TEST_CASE(SubmittingOfQuestionWithoutAnswer)
{
	CMultipleChoiceQuestionState state(question);
	BOOST_REQUIRE_THROW(state.GetReview(), logic_error);
	BOOST_REQUIRE_NO_THROW(state.Submit());
	BOOST_REQUIRE(!state.GetUserAnswerIndex());
	BOOST_REQUIRE_NO_THROW(state.GetReview());
	auto review = state.GetReview();
	BOOST_CHECK(!review.AnswerIsCorrect());
	BOOST_CHECK_EQUAL(review.GetAwardedScore(), 0.0);
}

BOOST_AUTO_TEST_CASE(SubmittingCorrectAnswer)
{
	CMultipleChoiceQuestionState state(question);
	state.SetUserAnswerIndex(1);
	state.Submit();
	auto review = state.GetReview();
	BOOST_CHECK(review.AnswerIsCorrect());
	BOOST_CHECK_EQUAL(review.GetAwardedScore(), 10.0);
}

BOOST_AUTO_TEST_CASE(SubmittingIncorrectAnswer)
{
	CMultipleChoiceQuestionState state(question);
	state.SetUserAnswerIndex(0);
	state.Submit();
	auto review = state.GetReview();
	BOOST_CHECK(!review.AnswerIsCorrect());
	BOOST_CHECK_EQUAL(review.GetAwardedScore(), 0.0);
}

BOOST_AUTO_TEST_CASE(ForbidChangingAnswerAfterSubmit)
{
	CMultipleChoiceQuestionState state(question);
	state.SetUserAnswerIndex(2);
	state.Submit();
	BOOST_REQUIRE_THROW(state.SetUserAnswerIndex(1), logic_error);
	BOOST_CHECK_EQUAL(state.GetUserAnswerIndex(), 2u);
}

BOOST_AUTO_TEST_SUITE_END()
