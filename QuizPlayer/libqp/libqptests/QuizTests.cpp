#include "stdafx.h"

#include "Quiz.h"
#include "Question.h"

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

	//add empty question collection
	quiz.SetQuestions(questions);
	BOOST_CHECK_EQUAL(questions.GetCount(), quiz.GetQuestions().GetCount());
	
	//add not empty question collection
	auto question1 = make_shared<CQuestion>("First question");
	auto question2 = make_shared<CQuestion>("Second question");
	questions.AddQuestion(question1);
	questions.AddQuestion(question2);
	quiz.SetQuestions(questions);
	BOOST_CHECK_EQUAL(questions.GetCount(), quiz.GetQuestions().GetCount());
	BOOST_CHECK_EQUAL(questions.GetQuestionAtIndex(0), quiz.GetQuestions().GetQuestionAtIndex(0));
	BOOST_CHECK_EQUAL(questions.GetQuestionAtIndex(1), quiz.GetQuestions().GetQuestionAtIndex(1));
}

BOOST_AUTO_TEST_SUITE_END()