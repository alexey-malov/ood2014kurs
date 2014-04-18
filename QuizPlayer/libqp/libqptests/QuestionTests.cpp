#include "stdafx.h"
#include "Question.h"

BOOST_AUTO_TEST_SUITE(QuestionTests)

using namespace qp;

BOOST_AUTO_TEST_CASE(Construction)
{
	CQuestion quest1("Question description");
	BOOST_REQUIRE_EQUAL(quest1.GetDescription(), "Question description");
	BOOST_REQUIRE_CLOSE(quest1.GetScore(), 0.0, 0.0001);
	BOOST_REQUIRE(!quest1.GetCorrectFeedback());
	BOOST_REQUIRE(!quest1.GetIncorrectFeedback());

	BOOST_REQUIRE_THROW(CQuestion quest2(""), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CorrectFeedbackCanBeChanged)
{
	CQuestion question("Description");
	question.SetCorrectFeedback("Non empty feedback");
	BOOST_REQUIRE(question.GetCorrectFeedback());
	BOOST_CHECK_EQUAL(question.GetCorrectFeedback().get(), "Non empty feedback");

	question.SetCorrectFeedback("");
	BOOST_REQUIRE(question.GetCorrectFeedback());
	BOOST_CHECK_EQUAL(question.GetCorrectFeedback().get(), "");
}

BOOST_AUTO_TEST_CASE(IncorrectFeedbackCanBeChanged)
{
	BOOST_MESSAGE("TODO: implement incorrect feedback changing for question");
}


BOOST_AUTO_TEST_SUITE_END()