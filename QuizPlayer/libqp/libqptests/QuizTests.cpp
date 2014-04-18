#include "stdafx.h"

#include "Quiz.h"

BOOST_AUTO_TEST_SUITE(Quiz)

using namespace qp;

BOOST_AUTO_TEST_CASE(QuizHasTitle)
{
	CQuiz quiz("Quiz title");
	BOOST_CHECK_EQUAL(quiz.GetTitle(), "Quiz title"); 
}

BOOST_AUTO_TEST_SUITE_END()