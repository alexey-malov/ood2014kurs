#include "stdafx.h"
#include "QuestionStateFactory.h"
#include "QuestionViewFactory.h"
#include "MatchingQuestion.h"
#include "MatchingQuestionView.h"
#include "IQuestionState.h"
#include "QuestionStateImpl.h"

BOOST_AUTO_TEST_SUITE(QuestionViewFactoryTests)

using namespace qp;
using namespace std;

CQuestionStateFactory stateFactory;
CQuestionViewFactory viewFactory;

BOOST_AUTO_TEST_CASE(MatchingQuestionViewCreationTest)
{
	CMatchingQuestion::MatchedItemsCollection matchedItems = { CMatchingQuestion::MatchedItems("1", "one"), CMatchingQuestion::MatchedItems("2", "two") };
	CMatchingQuestion::StandaloneItems extraItems = { "extra" };

	//CConstMatchingQuestionPtr matchingQuestionPtr(new CMatchingQuestion("MatchingQuestion description", 0.0, matchedItems, extraItems));
	//IQuestionStatePtr mqStatePtr = stateFactory.CreateStateForQuestion(matchingQuestionPtr);
	//auto mqViewPtr = viewFactory.CreateView(mqStatePtr);
	//BOOST_CHECK();
}

BOOST_AUTO_TEST_SUITE_END()