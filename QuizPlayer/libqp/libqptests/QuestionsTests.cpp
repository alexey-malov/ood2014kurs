#include "stdafx.h"
#include "Questions.h"
#include "Question.h"

BOOST_AUTO_TEST_SUITE(QuestionsTestSuite)

using namespace qp;
using namespace std;

BOOST_AUTO_TEST_CASE(QuestionsCollectionIsInitiallyEmpty)
{
	CQuestions questions;
	BOOST_CHECK_EQUAL(questions.GetCount(), 0u);
}

BOOST_AUTO_TEST_CASE(QuestionCanBeAddedToCollectionAndAccessed)
{
	CQuestions questions;
	auto question = make_shared<CQuestion>("Some question");
	questions.AddQuestion(question);
	BOOST_CHECK_EQUAL(questions.GetCount(), 1u);
	BOOST_CHECK_EQUAL(questions.GetQuestionAtIndex(0), question);

	//check index out of range
	BOOST_CHECK_THROW(questions.GetQuestionAtIndex(1), out_of_range);
}

BOOST_AUTO_TEST_CASE(SameQuestionsAreNotAdded)
{
	CQuestions questions;
	auto question = make_shared<CQuestion>("Some question");
	questions.AddQuestion(question);
	BOOST_CHECK_THROW(questions.AddQuestion(question), runtime_error);
	BOOST_CHECK_EQUAL(questions.GetCount(), 1u);
	BOOST_CHECK_EQUAL(questions.GetQuestionAtIndex(0), question);
}

BOOST_AUTO_TEST_CASE(DifferentQuestionsCanBeAdded)
{
	CQuestions questions;
	auto question = make_shared<CQuestion>("Some question");
	auto question1 = make_shared<CQuestion>("Another question");
	questions.AddQuestion(question);
	questions.AddQuestion(question1);
	BOOST_CHECK_EQUAL(questions.GetCount(), 2u);
	BOOST_CHECK_EQUAL(questions.GetQuestionAtIndex(0), question);
	BOOST_CHECK_EQUAL(questions.GetQuestionAtIndex(1), question1);
}

BOOST_AUTO_TEST_SUITE_END()
