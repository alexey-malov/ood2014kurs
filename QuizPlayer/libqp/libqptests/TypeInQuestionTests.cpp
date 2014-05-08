#include "stdafx.h"

#include "TypeInQuestion.h"

BOOST_AUTO_TEST_SUITE(TypeInQuestionSuite)

using namespace qp;
using namespace std;

BOOST_AUTO_TEST_CASE(Construction)
{
	CTypeInQuestion quest("Question description");
	BOOST_REQUIRE_EQUAL(quest.GetDescription(), "Question description");
	BOOST_REQUIRE_CLOSE(quest.GetScore(), 0.0, 0.0001);
}

BOOST_AUTO_TEST_CASE(QuestionHasCorrectAnswers)
{
	CTypeInQuestion quest("Question description");
	vector<string> answers = { "First answer", "Second answer" };
	quest.SetAnswers(answers);

	vector<string> const& gotAnswers = quest.GetAnswers();
	BOOST_REQUIRE(answers == gotAnswers);
}


BOOST_AUTO_TEST_SUITE_END()