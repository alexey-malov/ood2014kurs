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
	BOOST_MESSAGE("TODO: verify that question can be added to questions collection");
}

BOOST_AUTO_TEST_SUITE_END()
