#include "stdafx.h"
#include "MultipleChoiceQuestion.h"

BOOST_AUTO_TEST_SUITE(MultipleChoiceQuestionTests)

using namespace qp;

BOOST_AUTO_TEST_CASE(Construction)
{
	CMultipleChoiceQuestion quest1("Question description");
	BOOST_REQUIRE_EQUAL(quest1.GetDescription(), "Question description");
	BOOST_REQUIRE_CLOSE(quest1.GetScore(), 0.0, 0.0001);
}

BOOST_AUTO_TEST_CASE(QuestionHasChoices)
{
	CMultipleChoiceQuestion question("2+2=");
	BOOST_REQUIRE_EQUAL(question.GetAnswersCount(), 0u);

	question.AddChoice("3", false);
	BOOST_REQUIRE_EQUAL(question.GetAnswersCount(), 1u);
}

BOOST_AUTO_TEST_SUITE_END()