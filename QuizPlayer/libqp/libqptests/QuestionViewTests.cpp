#include "stdafx.h"

#include "Question.h"
#include "QuestionState.h"
#include "QuestionView.h"
#include "QuestionStateForTesting.h"
#include "QuestionForTest.h"

using namespace qp;
using namespace std;

struct QuestionViewTestsFixture
{
	QuestionViewTestsFixture()
	:state(make_shared<CQuestionStateForTesting>(make_shared<CQuestionForTest>("description", 10)))
	{
	}

	CQuestionStatePtr state;
	ostringstream ostrm;
};

BOOST_FIXTURE_TEST_SUITE(QuestionViewTests, QuestionViewTestsFixture)

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

	void ProcessString(std::string const& inputString) override
	{
		inputStrings.push_back(inputString);
		CQuestionView::ProcessString(inputString);
	}

	bool detailsWereShown;
	vector<string> inputStrings;
};

BOOST_AUTO_TEST_CASE(QuestionViewShowsDescriptionAndDetails)
{
	istringstream istrm;
	TestQuestionView view(state, ostrm, istrm);
	BOOST_REQUIRE_NO_THROW(view.Show());
	BOOST_CHECK_EQUAL(ostrm.str(), "description\n");
	BOOST_CHECK(view.detailsWereShown);
}

BOOST_AUTO_TEST_CASE(HandleUseInput)
{
	istringstream istrm("DoSomething\n");
	TestQuestionView view(state, ostrm, istrm);
	BOOST_REQUIRE_NO_THROW(view.HandleUserInput());
	BOOST_REQUIRE_EQUAL(view.inputStrings.size(), 1u);
	BOOST_REQUIRE_EQUAL(view.inputStrings[0], "DoSomething");
}

BOOST_AUTO_TEST_CASE(SubmitRequest)
{
	istringstream istrm("submit\n");
	TestQuestionView view(state, ostrm, istrm);
	bool submitRequested = false;
	view.SubmitRequested().connect([&submitRequested](){
		submitRequested = true;
	});
	BOOST_REQUIRE_NO_THROW(view.HandleUserInput());
	BOOST_CHECK(submitRequested);
}

BOOST_AUTO_TEST_SUITE_END()