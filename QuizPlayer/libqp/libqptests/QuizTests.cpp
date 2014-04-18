#include "stdafx.h"

#include "Quiz.h"

BOOST_AUTO_TEST_SUITE(Quiz)

using namespace qp;

BOOST_AUTO_TEST_CASE(QuizHasTitle)
{
	const CQuiz quiz("Quiz title");
	BOOST_CHECK_EQUAL(quiz.GetTitle(), "Quiz title"); 
}

BOOST_AUTO_TEST_CASE(QuizHasEmptyQuestions)
{
	const CQuiz quiz("Quiz");
	CQuestions const& questions = quiz.GetQuestions();
	BOOST_CHECK_EQUAL(questions.GetCount(), 0u);
}

BOOST_AUTO_TEST_SUITE_END()