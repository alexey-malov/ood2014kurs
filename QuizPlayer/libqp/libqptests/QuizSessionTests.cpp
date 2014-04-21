#include "stdafx.h"

#include "Quiz.h"
#include "QuizSession.h"

using namespace std;
using namespace qp;

struct QuizSessionTestSuiteFixture
{
	CQuizPtr quiz;
};

BOOST_FIXTURE_TEST_SUITE(QuizSessionTests, QuizSessionTestSuiteFixture)

BOOST_AUTO_TEST_CASE(SessionConstruction)
{
	CQuizSession session(quiz);

	BOOST_MESSAGE("TODO: verify initial state of quiz session");
}


BOOST_AUTO_TEST_SUITE_END()
