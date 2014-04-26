#include "stdafx.h"
#include "MultipleResponseQuestion.h"

BOOST_AUTO_TEST_SUITE(MultipleResponseQuestionTests)

using namespace qp;
using namespace std;

BOOST_AUTO_TEST_CASE(Construction)
{
	CMultipleResponseQuestion quest1("Question description");
	BOOST_REQUIRE_EQUAL(quest1.GetDescription(), "Question description");
	BOOST_REQUIRE_CLOSE(quest1.GetScore(), 0.0, 0.0001);
}

BOOST_AUTO_TEST_CASE(QuestionHasChoices)
{
	CMultipleResponseQuestion question("2+2=");

	BOOST_REQUIRE_NO_THROW({ CQuestionWithChoices& question2 = dynamic_cast<CQuestionWithChoices&>(question); question2; });
}


BOOST_AUTO_TEST_SUITE_END()