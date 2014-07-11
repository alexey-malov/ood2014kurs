#include "stdafx.h"
#include "QuestionViewControllerFactory.h"
#include "QuestionStateFactory.h"
#include "MatchingQuestion.h"
#include "MultipleChoiceQuestion_fwd.h"
#include "MultipleChoiceQuestion.h"
#include "MultipleChoiceQuestionViewController.h"
#include "IQuestionState.h"

using namespace std;
using namespace qp;

BOOST_AUTO_TEST_SUITE(QuestionViewControllerTests)

CQuestionStateFactory stateFactory;

BOOST_AUTO_TEST_CASE(MultipleChoiceQuestionViewControllerCreationTest)
{
	CConstMultipleChoiceQuestionPtr multipleChoiceQuestionPtr(new CMultipleChoiceQuestion("MultipleChoiceQuestion description", 0.0, CGradedChoices{ { "one", "two" } }));
	IQuestionStatePtr mcqStatePtr = stateFactory.CreateStateForQuestion(multipleChoiceQuestionPtr);
	CQuestionViewControllerFactory qvcFactory(&cout, &cin);
	shared_ptr<CQuestionViewController> mcqController = qvcFactory.CreateViewControllerForState(mcqStatePtr);
	BOOST_CHECK(dynamic_pointer_cast<CMultipleChoiceQuestionViewController>(mcqController));
}

BOOST_AUTO_TEST_SUITE_END()