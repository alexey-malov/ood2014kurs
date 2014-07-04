#include "stdafx.h"
#include "QuestionStateFactory.h"
#include "QuestionViewFactory.h"
#include "MatchingQuestion.h"
#include "MatchingQuestionView.h"
#include "IQuestionState.h"
#include "QuestionStateImpl.h"
#include "MultipleChoiceQuestion_fwd.h"
#include "MultipleChoiceQuestion.h"
#include "MultipleResponseQuestion_fwd.h"
#include "MultipleResponseQuestion.h"
#include "MatchingQuestionState.h"
#include "TypeInQuestion_fwd.h"
#include "TypeInQuestion.h"
#include "MultipleChoiceQuestionView.h"
#include "MultipleResponseQuestionView.h"
#include "TypeInQuestionView.h"

BOOST_AUTO_TEST_SUITE(QuestionViewFactoryTests)

using namespace qp;
using namespace std;

CQuestionStateFactory stateFactory;
CQuestionViewFactory viewFactory(&cout, &cin);

BOOST_AUTO_TEST_CASE(MatchingQuestionViewCreationTest)
{
	CMatchingQuestion::MatchedItemsCollection matchedItems = { CMatchingQuestion::MatchedItems("1", "one"), CMatchingQuestion::MatchedItems("2", "two") };
	CMatchingQuestion::StandaloneItems extraItems = { "extra" };

	CConstMatchingQuestionPtr matchingQuestionPtr(new CMatchingQuestion("MatchingQuestion description", 0.0, matchedItems, extraItems));
	IQuestionStatePtr mqStatePtr = stateFactory.CreateStateForQuestion(matchingQuestionPtr);
	BOOST_REQUIRE(dynamic_pointer_cast<IMatchingQuestionState>(mqStatePtr));
	auto mqViewPtr = viewFactory.CreateView(mqStatePtr);
	BOOST_CHECK(nullptr != dynamic_cast<CMatchingQuestionView*>(mqViewPtr.get()));
}

BOOST_AUTO_TEST_CASE(MultipleChoiceQuestionViewCreationTest)
{
	CConstMultipleChoiceQuestionPtr multipleChoiceQuestionPtr(new CMultipleChoiceQuestion("MultipleChoiceQuestion description", 0.0, CGradedChoices{ { "one", "two" } }));
	IQuestionStatePtr mcqStatePtr = stateFactory.CreateStateForQuestion(multipleChoiceQuestionPtr);
	auto mcqViewPtr = viewFactory.CreateView(mcqStatePtr);
	BOOST_CHECK(nullptr != dynamic_cast<CMultipleChoiceQuestionView*>(mcqViewPtr.get()));
}

BOOST_AUTO_TEST_CASE(MultipleResponseQuestionViewCreationTest)
{
	CConstMultipleResponseQuestionPtr multipleResponseQuestionPtr(new CMultipleResponseQuestion("MultipleResponseQuestion description", 0.0, CGradedChoices{ { "one", "two" } }));
	IQuestionStatePtr mrqStatePtr = stateFactory.CreateStateForQuestion(multipleResponseQuestionPtr);
	auto mrqViewPtr = viewFactory.CreateView(mrqStatePtr);
	BOOST_CHECK(nullptr != dynamic_cast<CMultipleResponseQuestionView*> (mrqViewPtr.get()));
}

BOOST_AUTO_TEST_CASE(TypeInQuestionViewCreationTest)
{
	CConstTypeInQuestionPtr typeInQuestionPtr(new CTypeInQuestion("TypeInQuestion description", set<string>{"one", "two"}, 0.0));
	IQuestionStatePtr tiqStatePtr = stateFactory.CreateStateForQuestion(typeInQuestionPtr);
	auto tiqViewPtr = viewFactory.CreateView(tiqStatePtr);
	BOOST_CHECK(nullptr != dynamic_cast<CTypeInQuestionView*> (tiqViewPtr.get()));
}

BOOST_AUTO_TEST_SUITE_END()