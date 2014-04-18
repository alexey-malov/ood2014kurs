#include "stdafx.h"
#include "Question.h"

BOOST_AUTO_TEST_SUITE(QuestionTests)

using namespace qp;

BOOST_AUTO_TEST_CASE(Constructor)
{
	CQuestion quest1("Question description");
	BOOST_REQUIRE_EQUAL(quest1.GetDescription(), "Question description");
	BOOST_REQUIRE_CLOSE(quest1.GetScore(), 1.0, 0.0001);
	BOOST_REQUIRE_EQUAL(quest1.GetCorrectFeedback(), "Correct Answer!");
	BOOST_REQUIRE_EQUAL(quest1.GetIncorrectFeedback(), "Incorrect Answer!");

	BOOST_REQUIRE_THROW(CQuestion quest2(""), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()