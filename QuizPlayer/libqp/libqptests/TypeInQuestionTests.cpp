#include "stdafx.h"

#include "TypeInQuestion.h"

BOOST_AUTO_TEST_SUITE(TypeInQuestionSuite)

using namespace qp;
using namespace std;

BOOST_AUTO_TEST_CASE(Construction)
{
	set<string> answers = { "First answer", "Second answer" };
	CTypeInQuestion quest("Question description", answers);
	BOOST_REQUIRE_EQUAL(quest.GetDescription(), "Question description");
	BOOST_REQUIRE_CLOSE(quest.GetScore(), 0.0, 0.0001);
}

BOOST_AUTO_TEST_CASE(QuestionHasCorrectAnswers)
{
	set<string> answers = { "First answer", "Second answer" };
	CTypeInQuestion quest("Question description", answers);

	set<string> const& gotAnswers = quest.GetAnswers();
	BOOST_REQUIRE(answers == gotAnswers);
}

BOOST_AUTO_TEST_CASE(QuestionHasNoEmptyAnswer)
{
	set<string> answers;
	BOOST_REQUIRE_THROW(CTypeInQuestion quest("Question description", answers), invalid_argument);
}

BOOST_AUTO_TEST_CASE(RemoveExtraSpacesInAnswers)
{
	set<string> answers1 = {"    Answer   with   extra spaces   "};
	CTypeInQuestion quest1("Question description", answers1);

	set<string> const& gotAnswers = quest1.GetAnswers();
	set<string> const& rightAnswers = {"Answer with extra spaces"};
	BOOST_REQUIRE(rightAnswers == gotAnswers);

	set<string> answers2 = {"     ", "Answer"};
	BOOST_REQUIRE_THROW(CTypeInQuestion quest2("Question description", answers2), invalid_argument);
}


BOOST_AUTO_TEST_SUITE_END()