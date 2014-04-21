#include "stdafx.h"

#include "QuestionState.h"
#include "Question.h"

using namespace qp;
using namespace std;

BOOST_AUTO_TEST_SUITE(QuestionStateTests)

BOOST_AUTO_TEST_CASE(InitialQuestionState)
{
	auto q = make_shared<CQuestion>("Question Description", 10);
	BOOST_CHECK_THROW((CQuestionState(nullptr)), invalid_argument);
	CQuestionState qs(q);
	BOOST_CHECK(!qs.Submitted());
}

BOOST_AUTO_TEST_SUITE_END()
