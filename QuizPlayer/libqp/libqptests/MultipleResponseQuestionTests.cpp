#include "stdafx.h"
#include "MultipleResponseQuestion.h"

BOOST_AUTO_TEST_SUITE(MultipleResponseQuestionTests)

using namespace qp;

BOOST_AUTO_TEST_CASE(Construction)
{
	CMultipleResponseQuestion quest1("Question description");
	BOOST_REQUIRE_EQUAL(quest1.GetDescription(), "Question description");
	BOOST_REQUIRE_CLOSE(quest1.GetScore(), 0.0, 0.0001);
}

BOOST_AUTO_TEST_CASE(CorrectFeedbackCanBeChanged)
{
	CMultipleResponseQuestion question("Description");
	question.SetCorrectFeedback("Non empty feedback");
	BOOST_REQUIRE(question.GetCorrectFeedback());
	BOOST_CHECK_EQUAL(question.GetCorrectFeedback().get(), "Non empty feedback");

	question.SetCorrectFeedback("");
	BOOST_REQUIRE(question.GetCorrectFeedback());
	BOOST_CHECK_EQUAL(question.GetCorrectFeedback().get(), "");
}

BOOST_AUTO_TEST_CASE(IncorrectFeedbackCanBeChanged)
{
	CMultipleResponseQuestion question("Description");
	question.SetIncorrectFeedback("Non empty feedback");
	BOOST_REQUIRE(question.GetIncorrectFeedback());
	BOOST_CHECK_EQUAL(question.GetIncorrectFeedback().get(), "Non empty feedback");

	question.SetIncorrectFeedback("");
	BOOST_REQUIRE(question.GetIncorrectFeedback());
	BOOST_CHECK_EQUAL(question.GetIncorrectFeedback().get(), "");
}

BOOST_AUTO_TEST_CASE(ScoreIsPassedAsAnOptionalParameterToConstructor)
{
	CMultipleResponseQuestion quest1("Question description", 2.0);
	BOOST_REQUIRE_CLOSE(quest1.GetScore(), 2.0, 0.0001);

	BOOST_REQUIRE_THROW(CMultipleResponseQuestion quest2("Question description", -2.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()