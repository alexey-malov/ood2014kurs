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

	CConstMatchingQuestionPtr matchingQuestionPtr(new CMatchingQuestion("MatchingQuestion description", 0.0, matchedItems, extraItems));
	auto mqStatePtr = f.CreateStateForQuestion(matchingQuestionPtr);
	BOOST_CHECK(nullptr != dynamic_cast<CMatchingQuestionState*> (mqStatePtr.get()));
}

BOOST_AUTO_TEST_CASE(MultipleChoiceQuestionStateCreationTest)
{
	CConstMultipleChoiceQuestionPtr multipleChoiceQuestionPtr(new CMultipleChoiceQuestion("MultipleChoiceQuestion description", 0.0, CGradedChoices{ { "one", "two" } }));
	auto mcqStatePtr = f.CreateStateForQuestion(multipleChoiceQuestionPtr);
	BOOST_CHECK(nullptr != dynamic_cast<CMultipleChoiceQuestionState*> (mcqStatePtr.get()));
}

BOOST_AUTO_TEST_CASE(MultipleResponseQuestionStateCreationTest)
{
	CConstMultipleResponseQuestionPtr multipleResponseQuestionPtr(new CMultipleResponseQuestion("MultipleResponseQuestion description", 0.0, CGradedChoices{ { "one", "two" } }));
	auto mrqStatePtr = f.CreateStateForQuestion(multipleResponseQuestionPtr);
	BOOST_CHECK(nullptr != dynamic_cast<CMultipleResponseQuestionState*> (mrqStatePtr.get()));
}

BOOST_AUTO_TEST_CASE(TypeInQuestionStateCreationTest)
{
	CConstTypeInQuestionPtr typeInQuestionPtr(new CTypeInQuestion("TypeInQuestion description", set<string>{"one", "two"}, 0.0));
	auto tiqStatePtr = f.CreateStateForQuestion(typeInQuestionPtr);
	BOOST_CHECK(nullptr != dynamic_cast<CTypeInQuestionState*> (tiqStatePtr.get()));
}

BOOST_AUTO_TEST_SUITE_END()