#include "stdafx.h"
#include "GradedChoice.h"
#include "QuestionWithChoices.h"

BOOST_AUTO_TEST_SUITE(QuestionWithChoicesTests)

using namespace qp;
using namespace std;

BOOST_AUTO_TEST_CASE(GradedChoicesCollection)
{
	CGradedChoices choices;

	BOOST_REQUIRE_EQUAL(choices.GetChoiceCount(), 0u);

	choices.AddChoice("3", false);
	BOOST_REQUIRE_EQUAL(choices.GetChoiceCount(), 1u);

	{
		GradedChoice choice = choices.GetChoice(0);
		BOOST_REQUIRE_EQUAL(choice.text, "3");
		BOOST_REQUIRE_EQUAL(choice.isCorrect, false);
	}

	choices.AddChoice("4", true);
	BOOST_REQUIRE_EQUAL(choices.GetChoiceCount(), 2u);
	BOOST_REQUIRE_THROW(choices.GetChoice(2), out_of_range);

	{
		GradedChoice choice = choices.GetChoice(1);
		BOOST_REQUIRE_EQUAL(choice.text, "4");
		BOOST_REQUIRE_EQUAL(choice.isCorrect, true);
	}
}

BOOST_AUTO_TEST_CASE(DuplicateChoice)
{
	CGradedChoices choices;
	choices.AddChoice("text 1", false);
	BOOST_REQUIRE_NO_THROW(choices.AddChoice("text 2", false));
	BOOST_REQUIRE_THROW(choices.AddChoice("text 2", false), invalid_argument);
	BOOST_REQUIRE_THROW(choices.AddChoice("text 2", true), invalid_argument);
}

BOOST_AUTO_TEST_CASE(QuestionConstruction)
{
	CQuestionWithChoices question("Question description");
	BOOST_REQUIRE_EQUAL(question.GetDescription(), "Question description");
	BOOST_REQUIRE_CLOSE(question.GetScore(), 0.0, 0.0001);
}

BOOST_AUTO_TEST_CASE(ChoicesAccessors)
{
	CQuestionWithChoices question("Question description");
	CGradedChoices choices;
	choices.AddChoice("3", false);
	choices.AddChoice("4", true);
	question.SetChoices(choices);
	CGradedChoices choices2 = question.GetChoices();
	BOOST_REQUIRE_EQUAL(choices.GetChoiceCount(), choices2.GetChoiceCount());
	BOOST_REQUIRE_EQUAL(choices.GetChoice(0).text, choices2.GetChoice(0).text);
	BOOST_REQUIRE_EQUAL(choices.GetChoice(0).isCorrect, choices2.GetChoice(0).isCorrect);
	BOOST_REQUIRE_EQUAL(choices.GetChoice(1).text, choices2.GetChoice(1).text);
	BOOST_REQUIRE_EQUAL(choices.GetChoice(1).isCorrect, choices2.GetChoice(1).isCorrect);
}

BOOST_AUTO_TEST_SUITE_END()