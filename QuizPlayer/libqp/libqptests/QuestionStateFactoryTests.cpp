#include "stdafx.h"
#include "QuestionStateFactory.h"
#include "MatchingQuestion.h"
#include "MatchingQuestionState.h"
#include "MultipleChoiceQuestion.h"
#include "MultipleChoiceQuestionState.h"
#include "MultipleResponseQuestion.h"
#include "MultipleResponseQuestionState.h"
#include "TypeInQuestion.h"
#include "TypeInQuestionState.h"

BOOST_AUTO_TEST_SUITE(QuestionTests)

using namespace qp;
using namespace std;

CQuestionStateFactory f;

BOOST_AUTO_TEST_CASE(MatchingQuestionStateCreationTest)
{
	CMatchingQuestion::MatchedItemsCollection matchedItems = { CMatchingQuestion::MatchedItems("1", "one"), CMatchingQuestion::MatchedItems("2", "two") };
	CMatchingQuestion::StandaloneItems extraItems = { "extra" };

	CConstMatchingQuestionPtr mqPtr(new CMatchingQuestion("MatchingQuestion description", 0.0, matchedItems, extraItems));
	auto mqStatePtr = f.CreateStateForQuestion(mqPtr);
	BOOST_CHECK(nullptr != dynamic_cast<CMatchingQuestionState*> (mqStatePtr.get()));
}

BOOST_AUTO_TEST_CASE(MultipleChoiceQuestionStateCreationTest)
{
	CConstMultipleChoiceQuestionPtr mcqPtr(new CMultipleChoiceQuestion("MultipleChoiceQuestion description", 0.0, CGradedChoices{ { "raz", "dwa" } }));
	auto mcqStatePtr = f.CreateStateForQuestion(mcqPtr);
	BOOST_CHECK(nullptr != dynamic_cast<CMultipleChoiceQuestionState*> (mcqStatePtr.get()));
}

BOOST_AUTO_TEST_CASE(MultipleResponseQuestionStateCreationTest)
{
	CConstMultipleResponseQuestionPtr mrqPtr(new CMultipleResponseQuestion("MultipleResponseQuestion description", 0.0, CGradedChoices{ { "raz", "dwa" } }));
	auto mrqStatePtr = f.CreateStateForQuestion(mrqPtr);
	BOOST_CHECK(nullptr != dynamic_cast<CMultipleResponseQuestionState*> (mrqStatePtr.get()));
}

BOOST_AUTO_TEST_CASE(TypeInQuestionStateCreationTest)
{
	CConstTypeInQuestionPtr tiqPtr(new CTypeInQuestion("TypeInQuestion description", set<string>{"raz", "dwa"}, 0.0));
	auto tiqStatePtr = f.CreateStateForQuestion(tiqPtr);
	BOOST_CHECK(nullptr != dynamic_cast<CTypeInQuestionState*> (tiqStatePtr.get()));
}

BOOST_AUTO_TEST_SUITE_END()