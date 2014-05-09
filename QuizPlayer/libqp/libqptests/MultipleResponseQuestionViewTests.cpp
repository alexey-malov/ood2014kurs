#include "stdafx.h"

#include "Question.h"
#include "MultipleResponseQuestion.h"
#include "QuestionState.h"
#include "QuestionView.h"
#include "MultipleResponseQuestionView.h"
#include "QuestionStateForTesting.h"

using namespace qp;
using namespace std;

BOOST_AUTO_TEST_SUITE(MultipleResponseQuestionViewTests)

BOOST_AUTO_TEST_CASE(MultipleResponseQuestionViewShowsDescriptionAndDetails)
{
	string description = "Description";
	auto question = make_shared<CMultipleResponseQuestion>(description, 10);
	auto state = make_shared<CQuestionStateForTesting>(question);
	
	struct TestQuestionView : public CMultipleResponseQuestionView
	{
		TestQuestionView(const CQuestionStatePtr & questionState, std::ostream & outputStream)
		:CMultipleResponseQuestionView(questionState, outputStream)
		, detailsWereShown(false)
		{}

		void ShowDetails() override
		{
			detailsWereShown = true;
		}

		bool detailsWereShown;
	};
	
	ostringstream ostrm;
	TestQuestionView view(state, ostrm);
	view.Show();
	BOOST_CHECK_EQUAL(ostrm.str(), description + "\n");
	BOOST_CHECK(view.detailsWereShown);
	
}


BOOST_AUTO_TEST_SUITE_END()