#include "stdafx.h"

#include "Quiz.h"

BOOST_AUTO_TEST_SUITE(QuizTestSuite)

using namespace qp;
using namespace std;

BOOST_AUTO_TEST_CASE(QuizHasTitle)
{
	const CQuiz quiz("Quiz title");
	BOOST_CHECK_EQUAL(quiz.GetTitle(), "Quiz title"); 
}

BOOST_AUTO_TEST_CASE(QuizInitiallyHasEmptyQuestionsCollection)
{
	const CQuiz constQuiz;
	const CQuestions & questions = constQuiz.GetQuestions();
	BOOST_CHECK_EQUAL(questions.GetCount(), 0u);
}

BOOST_AUTO_TEST_CASE(CanAssignQuestionsToQuiz)
{
	CQuiz quiz;
	CQuestions questions;
	BOOST_MESSAGE("TODO: add some questions to questions collection");
	quiz.SetQuestions(questions);
	BOOST_MESSAGE("TODO: verity that quiz questions collection has been updated");

}

BOOST_AUTO_TEST_SUITE_END()