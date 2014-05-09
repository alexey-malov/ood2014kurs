#include "stdafx.h"
#include "GradedChoice.h"
#include "QuestionWithChoices.h"

BOOST_AUTO_TEST_SUITE(QuestionWithChoicesTests)

using namespace qp;
using namespace std;

class CQuestionWithChoicesForTest : public CQuestionWithChoices
{
public:
	LOKI_DEFINE_CONST_VISITABLE()
	CQuestionWithChoicesForTest(std::string const &description, double score = 0.0, const CGradedChoices & choices = CGradedChoices())
		:CQuestionWithChoices(description, score, choices)
	{
	}
};

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

BOOST_AUTO_TEST_CASE(GradedChoicesCollectionConstructionWithInitializerList)
{
	CGradedChoices choices({ 
		{ "Correct", true }, 
		{ "Incorrect", false } 
	});

	BOOST_REQUIRE_EQUAL(choices.GetChoiceCount(), 2u);

	BOOST_CHECK_EQUAL(choices.GetChoice(0).text, "Correct");
	BOOST_CHECK(choices.GetChoice(0).isCorrect);

	BOOST_CHECK_EQUAL(choices.GetChoice(1).text, "Incorrect");
	BOOST_CHECK(!choices.GetChoice(1).isCorrect);

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
	CQuestionWithChoicesForTest question("Question description", 666.5);
	BOOST_REQUIRE_EQUAL(question.GetDescription(), "Question description");
	BOOST_REQUIRE_CLOSE(question.GetScore(), 666.5, 0.0001);
	BOOST_REQUIRE_EQUAL(question.GetChoices().GetChoiceCount(), 0u);
}

BOOST_AUTO_TEST_CASE(QuestionConstructionWithChoices)
{
	CGradedChoices choices;
	choices.AddChoice("Text", true);
	CQuestionWithChoicesForTest q("Desc", 7, choices);
	auto & questionChoices = q.GetChoices();
	BOOST_REQUIRE_EQUAL(questionChoices.GetChoiceCount(), 1u);
	auto & choice0 = questionChoices.GetChoice(0);
	BOOST_CHECK_EQUAL(choice0.text, "Text");
	BOOST_CHECK(choice0.isCorrect);
}



BOOST_AUTO_TEST_CASE(ChoicesAccessors)
{
	CQuestionWithChoicesForTest question("Question description");
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