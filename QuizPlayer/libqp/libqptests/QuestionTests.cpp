#include "stdafx.h"
#include "Question.h"
#include "QuestionForTest.h"


BOOST_AUTO_TEST_SUITE(QuestionTests)

using namespace qp;
using namespace std;



BOOST_AUTO_TEST_CASE(Construction)
{
	CQuestionForTest quest1("Question description");
	BOOST_REQUIRE_EQUAL(quest1.GetDescription(), "Question description");
	BOOST_REQUIRE_CLOSE(quest1.GetScore(), 0.0, 0.0001);
	BOOST_REQUIRE(!quest1.GetCorrectFeedback());
	BOOST_REQUIRE(!quest1.GetIncorrectFeedback());

	BOOST_REQUIRE_THROW(CQuestionForTest quest2(""), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CorrectFeedbackCanBeChanged)
{
	CQuestionForTest question("Description");
	question.SetCorrectFeedback("Non empty feedback");
	BOOST_REQUIRE(question.GetCorrectFeedback());
	BOOST_CHECK_EQUAL(question.GetCorrectFeedback().get(), "Non empty feedback");

	question.SetCorrectFeedback("");
	BOOST_REQUIRE(question.GetCorrectFeedback());
	BOOST_CHECK_EQUAL(question.GetCorrectFeedback().get(), "");
}

BOOST_AUTO_TEST_CASE(IncorrectFeedbackCanBeChanged)
{
	CQuestionForTest question("Description");
	question.SetIncorrectFeedback("Non empty feedback");
	BOOST_REQUIRE(question.GetIncorrectFeedback());
	BOOST_CHECK_EQUAL(question.GetIncorrectFeedback().get(), "Non empty feedback");

	question.SetIncorrectFeedback("");
	BOOST_REQUIRE(question.GetIncorrectFeedback());
	BOOST_CHECK_EQUAL(question.GetIncorrectFeedback().get(), "");
}

BOOST_AUTO_TEST_CASE(ScoreIsPassedAsAnOptionalParameterToConstructor)
{
	CQuestionForTest quest1("Question description", 2.0);
	BOOST_REQUIRE_CLOSE(quest1.GetScore(), 2.0, 0.0001);

	BOOST_REQUIRE_THROW(CQuestionForTest quest2("Question description", -2.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(QuestionCanAcceptVisitor)
{
	struct MockVisitor 
		: Loki::BaseVisitor
		, Loki::Visitor<CQuestionForTest, void, true>
	{

		void Visit(CQuestionForTest const& question)
		{
			visitedQuestions.push_back(&question);
		}
		vector<CQuestionForTest const*> visitedQuestions;
	};


	const CQuestionForTest q1("Question description");
	MockVisitor visitor;
	q1.Accept(visitor);
	BOOST_REQUIRE_EQUAL(visitor.visitedQuestions.size(), 1u);
	BOOST_REQUIRE_EQUAL(visitor.visitedQuestions[0], &q1);
}

BOOST_AUTO_TEST_SUITE_END()