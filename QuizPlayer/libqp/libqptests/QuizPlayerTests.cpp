#include "stdafx.h"
#include "QuizPlayer.h"
#include "Quiz.h"
#include "MockQuizView.h"
//#include <vld.h> // Visual Leak Detector. Download and install from http://vld.codeplex.com

using namespace qp;
using namespace std;

struct QuizPlayerTestSuiteFixture
{
	QuizPlayerTestSuiteFixture()  
	:quiz(make_shared<CQuiz>("Quiz title"))
	{

	}
	CQuizPtr quiz;
	CMockQuizView mockView;
};

BOOST_FIXTURE_TEST_SUITE(QuizPlayerTests, QuizPlayerTestSuiteFixture)


BOOST_AUTO_TEST_CASE(QuizPlayerCanStartQuiz)
{
	CQuizPlayer qp(quiz, mockView);
	//BOOST_REQUIRE_NO_THROW(qp.Start());

	BOOST_MESSAGE("TODO: implement QuizPlayerTestSuiteFixture");
}

BOOST_AUTO_TEST_SUITE_END()