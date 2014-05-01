#include "stdafx.h"

#include "Quiz.h"
#include "QuizSession.h"
#include "QuestionStates.h"
#include "MultipleChoiceQuestion.h"
#include "MultipleChoiceQuestionState.h"

using namespace std;
using namespace qp;

struct QuizSessionTestSuiteFixture
{
	QuizSessionTestSuiteFixture()
	:quiz(make_shared<CQuiz>("Quiz Title"))
	, question1(CreateMultipleChoiceQuestion("Multiple choice question", 10, {
		{ "Correct", true }, 
		{ "Incorrect", false } 
	}))
	{
		CQuestions questions;
		questions.AddQuestion(question1);
		quiz->SetQuestions(questions);
	}

	static CMultipleChoiceQuestionPtr CreateMultipleChoiceQuestion(
		const string & description, 
		double score, 
		const initializer_list<GradedChoice> &choices)
	{
		return make_shared<CMultipleChoiceQuestion>(description, score, choices);
	}

	CQuizPtr quiz;
	CMultipleChoiceQuestionPtr question1;

};

BOOST_FIXTURE_TEST_SUITE(QuizSessionTests, QuizSessionTestSuiteFixture)

BOOST_AUTO_TEST_CASE(SessionConstruction)
{
	CQuestionStates questionStates;
	questionStates.AddQuestionState(make_shared<CMultipleChoiceQuestionState>(question1));

	CQuizSession session(quiz, questionStates);
	auto & sessionQuestionStates = session.GetQuestionStates();
	BOOST_REQUIRE_EQUAL(sessionQuestionStates.GetCount(), questionStates.GetCount());
	BOOST_CHECK_EQUAL(sessionQuestionStates.GetQuestionStateAtIndex(0), questionStates.GetQuestionStateAtIndex(0));
}

BOOST_AUTO_TEST_SUITE_END()
