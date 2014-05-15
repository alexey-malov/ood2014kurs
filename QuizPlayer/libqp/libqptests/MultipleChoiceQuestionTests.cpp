#include "stdafx.h"
#include "MultipleChoiceQuestion.h"

BOOST_AUTO_TEST_SUITE(MultipleChoiceQuestionTests)

using namespace qp;
using namespace std;

BOOST_AUTO_TEST_CASE(ConstructionWithoutChoices)
{
	CMultipleChoiceQuestion quest1("Question description", 123.3);
	BOOST_REQUIRE_EQUAL(quest1.GetDescription(), "Question description");
	BOOST_REQUIRE_CLOSE(quest1.GetScore(), 123.3, 0.0001);
	BOOST_REQUIRE_EQUAL(quest1.GetChoices().GetChoiceCount(), 0u);
}

BOOST_AUTO_TEST_CASE(ConstructionWithChoices)
{
	CMultipleChoiceQuestion question("desc", 10, CGradedChoices({ { "Correct", true }, { "Incorrect", false }}));
	BOOST_REQUIRE_EQUAL(question.GetChoices().GetChoiceCount(), 2u);
}

BOOST_AUTO_TEST_CASE(QuestionHasChoices)
{
	CMultipleChoiceQuestion question("2+2=");

	BOOST_REQUIRE_NO_THROW({ CQuestionWithChoices& question2 = dynamic_cast<CQuestionWithChoices&>(question); question2; });
}


BOOST_AUTO_TEST_SUITE_END()