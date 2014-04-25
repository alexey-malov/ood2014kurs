#include "stdafx.h"
#include "MultipleChoiceQuestion.h"

BOOST_AUTO_TEST_SUITE(MultipleChoiceQuestionTests)

using namespace qp;
using namespace std;

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

	{
		GradedChoice choice = question.GetChoice(0);
		BOOST_REQUIRE_EQUAL(choice.text, "3");
		BOOST_REQUIRE_EQUAL(choice.isCorrect, false);
	}

	question.AddChoice("4", true);
	BOOST_REQUIRE_EQUAL(question.GetAnswersCount(), 2u);
	BOOST_REQUIRE_THROW(question.GetChoice(2), out_of_range);
	
	{
		GradedChoice choice = question.GetChoice(1);
		BOOST_REQUIRE_EQUAL(choice.text, "4");
		BOOST_REQUIRE_EQUAL(choice.isCorrect, true);
	}
}


BOOST_AUTO_TEST_SUITE_END()