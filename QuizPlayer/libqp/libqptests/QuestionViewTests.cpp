#include "stdafx.h"

#include "Question.h"
#include "QuestionState.h"
#include "QuestionView.h"
#include "QuestionStateForTesting.h"
#include "QuestionForTest.h"

using namespace qp;
using namespace std;

BOOST_AUTO_TEST_SUITE(QuestionViewTests)

BOOST_AUTO_TEST_CASE(QuestionViewShowsDescriptionAndDetails)
{
	string description = "Description";
	auto question = make_shared<CQuestionForTest>(description, 10);
	auto state = make_shared<CQuestionStateForTesting>(question);
	
	struct TestQuestionView : public CQuestionView
	{
		TestQuestionView(const CQuestionStatePtr & questionState, std::ostream & outputStream, std::istream & inputStream)
		:CQuestionView(questionState, outputStream, inputStream)
		,detailsWereShown(false)
		{}

		void ShowDetails() override
		{
			detailsWereShown = true;
		}

		bool detailsWereShown;
	};

	ostringstream ostrm;
	istringstream istrm;
	TestQuestionView view(state, ostrm, istrm);
	BOOST_REQUIRE_NO_THROW(view.Show());
	BOOST_CHECK_EQUAL(ostrm.str(), description + "\n");
	BOOST_CHECK(view.detailsWereShown);
	
}


BOOST_AUTO_TEST_SUITE_END()