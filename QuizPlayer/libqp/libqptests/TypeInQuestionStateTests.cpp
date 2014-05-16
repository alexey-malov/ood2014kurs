#include "stdafx.h"

#include "TypeInQuestion.h"
#include "TypeInQuestionState.h"
#include "QuestionReview.h"

using namespace qp;
using namespace std;

set<string> TypeInAnswersCollection = { "First answer", "Second answer" };

struct TypeInQuestionStateTestFixture
{

	TypeInQuestionStateTestFixture()
	:question(make_shared<CTypeInQuestion>("Question description", TypeInAnswersCollection, 10))
	{
		
	}

	CTypeInQuestionPtr question;
};

BOOST_FIXTURE_TEST_SUITE(TypeInQuestionStateTests, TypeInQuestionStateTestFixture)

BOOST_AUTO_TEST_CASE(Construction)
{
	CTypeInQuestionState state(question);
	BOOST_REQUIRE_EQUAL(state.GetUserAnswer(), "");
}

BOOST_AUTO_TEST_CASE(CheckSettingUserAnswer)
{
	CTypeInQuestionState state(question);

	std::string answer = "First answer";
	state.SetUserAnswer(answer);

	BOOST_REQUIRE_EQUAL(state.GetUserAnswer(), answer);
}

BOOST_AUTO_TEST_CASE(RemoveExtraSpacesInUserAnswer)
{
	CTypeInQuestionState state(question);

	std::string answer = "  First    answer   ";
	state.SetUserAnswer(answer);

	BOOST_REQUIRE_EQUAL(state.GetUserAnswer(), "First answer");
}

void VerifyReview(CTypeInQuestionState &questionState, double expectedScore, bool isCorrect)
{
	BOOST_REQUIRE_NO_THROW(questionState.Submit());
	BOOST_REQUIRE_NO_THROW(questionState.GetReview());
	auto review = questionState.GetReview();
	BOOST_CHECK(review.AnswerIsCorrect() == isCorrect);
	BOOST_CHECK_EQUAL(review.GetAwardedScore(), expectedScore);
}

BOOST_AUTO_TEST_CASE(SubmittingCorrectAnswer)
{
	CTypeInQuestionState state(question);
	state.SetUserAnswer("First answer");
	BOOST_REQUIRE_NO_THROW(VerifyReview(state, 10.0, true));
}


BOOST_AUTO_TEST_SUITE_END()