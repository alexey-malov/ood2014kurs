#include "stdafx.h"

#include "TypeInQuestion.h"
#include "TypeInQuestionState.h"
#include "QuestionReview.h"

using namespace qp;
using namespace std;

set<string> TypeInAnswersCollection = { "First answer", "Second answer" };

struct TypeInQuestionStateTestFixture
{

	TypeInQuestionStateTestFixture()
	:question(make_shared<CTypeInQuestion>("Question description", TypeInAnswersCollection, 10))
	{
		
	}

	CTypeInQuestionPtr question;
};

BOOST_FIXTURE_TEST_SUITE(TypeInQuestionStateTests, TypeInQuestionStateTestFixture)

BOOST_AUTO_TEST_CASE(Construction)
{
	CTypeInQuestionState state(question);
	BOOST_REQUIRE_EQUAL(state.GetUserAnswer(), "");
}

BOOST_AUTO_TEST_CASE(CheckSettingUserAnswer)
{
	CTypeInQuestionState state(question);

	std::string answer = "First answer";
	state.SetUserAnswer(answer);

	BOOST_REQUIRE_EQUAL(state.GetUserAnswer(), answer);
}


BOOST_AUTO_TEST_SUITE_END()