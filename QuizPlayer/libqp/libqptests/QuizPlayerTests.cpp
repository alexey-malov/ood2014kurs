#include "stdafx.h"
#include "QuizPlayer.h"
#include "Quiz.h"
#include "MockQuizView.h"

using namespace qp;
using namespace std;

struct QuizPlayerTestSuiteFixture
{
	CQuizPtr quiz;
	CMockQuizView mockView;
};

BOOST_FIXTURE_TEST_SUITE(QuizPlayerTests, QuizPlayerTestSuiteFixture)


BOOST_AUTO_TEST_CASE(QuizPlayerCanStartQuiz)
{
	CQuizPlayer qp(quiz, mockView);
	BOOST_REQUIRE_NO_THROW(qp.Start());

	BOOST_MESSAGE("TODO: implement this test");
}

BOOST_AUTO_TEST_SUITE_END()