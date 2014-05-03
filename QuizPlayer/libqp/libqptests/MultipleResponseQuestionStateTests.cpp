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


// не имеет смысла - вопрос может не содержать правильных ответов
/*
BOOST_AUTO_TEST_CASE(SubmittingOfQuestionWithoutAnswer)
{
	CMultipleResponseQuestionState state(question);
	BOOST_REQUIRE_THROW(state.GetReview(), logic_error);
	BOOST_REQUIRE_NO_THROW(state.Submit());
	//BOOST_REQUIRE(!state.GetUserAnswerIndex());
	BOOST_REQUIRE_NO_THROW(state.GetReview());
	auto review = state.GetReview();
	BOOST_CHECK(!review.AnswerIsCorrect());
	BOOST_CHECK_EQUAL(review.GetAwardedScore(), 0.0);
}
*/

BOOST_AUTO_TEST_CASE(SubmittingCorrectAnswer)
{
	CMultipleResponseQuestionState state(question);
	state.SetUserResponse(1);
	state.SetUserResponse(3);
	state.Submit();
	auto review = state.GetReview();
	BOOST_CHECK(review.AnswerIsCorrect());
	BOOST_CHECK_EQUAL(review.GetAwardedScore(), 10.0);
}

BOOST_AUTO_TEST_CASE(SubmittingIncorrectAnswer)
{
	CMultipleResponseQuestionState state(question);
	state.SetUserResponse(3);
	state.Submit();
	auto review = state.GetReview();
	BOOST_CHECK(!review.AnswerIsCorrect());
	BOOST_CHECK_EQUAL(review.GetAwardedScore(), 0.0);
}


BOOST_AUTO_TEST_CASE(ForbidChangingAnswerAfterSubmit)
{
	CMultipleResponseQuestionState state(question);
	state.SetUserResponse(3);
	state.Submit();
	BOOST_REQUIRE_THROW(state.ResetUserResponse(3), logic_error);
	BOOST_CHECK_EQUAL(state.GetUserResponse(3), true);
}

BOOST_AUTO_TEST_SUITE_END()
