#include "stdafx.h"

#include "MatchingQuestion.h"
#include "MatchingQuestionState.h"
#include "QuestionReview.h"

using namespace qp;
using namespace std;
using MatchedItems = CMatchingQuestion::MatchedItems;
using StandaloneItems = CMatchingQuestion::StandaloneItems;
using MatchedItemsCollection = CMatchingQuestion::MatchedItemsCollection;

MatchedItemsCollection matchedItems = { 
	MatchedItems("1", "one"), 
	MatchedItems("2", "two"), 
	MatchedItems("3", "three") 
};
StandaloneItems extraItems = { "extra" };
struct MatchingQuestionStateTestFixture : boost::noncopyable
{
	MatchingQuestionStateTestFixture()
	:question(make_shared<CMatchingQuestion>("Question description", 10, matchedItems, extraItems))
	{
	}

	CConstMatchingQuestionPtr const question;
};

BOOST_FIXTURE_TEST_SUITE(MatchingQuestionStateTests, MatchingQuestionStateTestFixture)

void VerifyReview(CMatchingQuestionState & questionState, double expectedScore, bool isCorrect)
{
	BOOST_REQUIRE_NO_THROW(questionState.Submit());
	BOOST_REQUIRE_NO_THROW(questionState.GetReview());
	auto review = questionState.GetReview();
	BOOST_CHECK(review.AnswerIsCorrect() == isCorrect);
	BOOST_CHECK_EQUAL(review.GetAwardedScore(), expectedScore);
}

BOOST_AUTO_TEST_CASE(Construction)
{
	CMatchingQuestionState state(question);
	BOOST_REQUIRE_EQUAL(state.GetLeftIndexes().size(), 3u);
	BOOST_REQUIRE_EQUAL(state.GetRightIndexes().size(), 4u);
	BOOST_REQUIRE_EQUAL(state.GetResponses().size(), 3u);
}

BOOST_AUTO_TEST_CASE(CheckInputQuestionInConstructor)
{
	{
		CConstMatchingQuestionPtr mq = make_shared<CMatchingQuestion>("Question description", 10);
		BOOST_REQUIRE_THROW(CMatchingQuestionState state(mq), invalid_argument);
	}
	{
	MatchedItemsCollection matchedItems;
	StandaloneItems extraItems = { "extra" };
	CConstMatchingQuestionPtr mq;
	BOOST_REQUIRE_NO_THROW(mq = make_shared<CMatchingQuestion>("Question description", 10, matchedItems, extraItems));
	BOOST_REQUIRE_THROW(CMatchingQuestionState state(mq), invalid_argument);
}
	{
		MatchedItemsCollection matchedItems = { MatchedItems("1", "zero") };
		StandaloneItems extraItems = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27" };
		CConstMatchingQuestionPtr mq;
		BOOST_REQUIRE_NO_THROW(mq = make_shared<CMatchingQuestion>("Question description", 10, matchedItems, extraItems));
		BOOST_REQUIRE_THROW(CMatchingQuestionState state(mq), invalid_argument);
	}
}

BOOST_AUTO_TEST_CASE(SelectResponse)
{
	CMatchingQuestionState state(question);
	BOOST_CHECK(!state.GetResponses().at(0));
	state.SelectResponse(0, 0);
	BOOST_CHECK_EQUAL(*state.GetResponses().at(0), 0u);

	state.SelectResponse(0, 1);
	BOOST_CHECK_EQUAL(*state.GetResponses().at(0), 1u);

	BOOST_REQUIRE_THROW(state.SelectResponse(3, 0), out_of_range);
	BOOST_REQUIRE_THROW(state.SelectResponse(0, 4), out_of_range);
	BOOST_REQUIRE_THROW(state.SelectResponse(1, 1), logic_error);
}

BOOST_AUTO_TEST_CASE(UnselectResponse)
{
	CMatchingQuestionState state(question);
	BOOST_REQUIRE_NO_THROW(state.UnselectResponse(0));
	BOOST_CHECK(!state.GetResponses().at(0));

	state.SelectResponse(0, 0);
	state.UnselectResponse(0);
	BOOST_CHECK(!state.GetResponses().at(0));

	BOOST_CHECK_THROW(state.UnselectResponse(3), out_of_range);
}

BOOST_AUTO_TEST_CASE(SubmittingOfQuestionWithoutAnswer)
{
	CMatchingQuestionState state(question);
	BOOST_REQUIRE_THROW(state.GetReview(), logic_error);
	BOOST_REQUIRE_THROW(state.Submit(), logic_error);
}

BOOST_AUTO_TEST_CASE(SubmittingOfQuestionWithPartialAnswer)
{
	CMatchingQuestionState state(question);
	state.SelectResponse(0, 0);
	state.SelectResponse(1, 3);
	BOOST_REQUIRE_THROW(state.Submit(), logic_error);
}

size_t FindMatchedItem(CMatchingQuestionState & state, size_t index)
{
	auto realLeftIndex = state.GetLeftIndexes().at(index);
	auto const& rightItems = state.GetRightIndexes();
	auto it = find(rightItems.begin(), rightItems.end(), realLeftIndex);
	if (it == rightItems.end())
	{
		throw invalid_argument("Undefined error. Matched item is not found.");
	}
	return (size_t)(it - rightItems.begin());
}

BOOST_AUTO_TEST_CASE(SubmittingOfCorrectAnswer)
{
	CMatchingQuestionState state(question);
	state.SelectResponse(0u, FindMatchedItem(state, 0));
	state.SelectResponse(1u, FindMatchedItem(state, 1));
	state.SelectResponse(2u, FindMatchedItem(state, 2));
	VerifyReview(state, 10, true);
}

BOOST_AUTO_TEST_CASE(SubmittingOfIncorrectAnswer)
{
	CMatchingQuestionState state(question);
	state.SelectResponse(0u, FindMatchedItem(state, 1));
	state.SelectResponse(1u, FindMatchedItem(state, 0));
	state.SelectResponse(2u, FindMatchedItem(state, 2));
	VerifyReview(state, 0, false);
}

BOOST_AUTO_TEST_CASE(ForbidChangingAnswerAfterSubmit)
{
	CMatchingQuestionState state(question);
	state.SelectResponse(0u, 0u);
	state.SelectResponse(1u, 1u);
	state.SelectResponse(2u, 2u);
	state.Submit();
	BOOST_REQUIRE_THROW(state.SelectResponse(0, 3), logic_error);
	BOOST_REQUIRE_THROW(state.UnselectResponse(0), logic_error);
}

BOOST_AUTO_TEST_CASE(GetQuestionReturnsMatchingQuestion)
{
	CMatchingQuestionState qs(question);
	CConstMatchingQuestionPtr receivedQuestion = qs.GetConcreteQuestion();
	BOOST_REQUIRE_EQUAL(receivedQuestion, question);
}

BOOST_AUTO_TEST_CASE(MatchingQuestionWithoutShufflingAnswers)
{
	CMatchingQuestionState qs(question, false);
	auto const& leftIndexes = qs.GetLeftIndexes();
	for (size_t i = 0; i < leftIndexes.size(); ++i)
	{
		BOOST_REQUIRE_EQUAL(i, leftIndexes[i]);
	}

	auto const& rightIndexes = qs.GetRightIndexes();
	for (size_t i = 0; i < rightIndexes.size(); ++i)
	{
		BOOST_REQUIRE_EQUAL(i, rightIndexes[i]);
	}
}

BOOST_AUTO_TEST_SUITE_END()