#include "stdafx.h"

#include "Quiz.h"
#include "QuizSession.h"

using namespace std;
using namespace qp;

struct QuizSessionTestSuiteFixture
{
	QuizSessionTestSuiteFixture()
	:quiz(make_shared<CQuiz>("Quiz Title"))
	{

	}
	CQuizPtr quiz;
};

BOOST_FIXTURE_TEST_SUITE(QuizSessionTests, QuizSessionTestSuiteFixture)


BOOST_AUTO_TEST_SUITE_END()
