#include "stdafx.h"

#include "MultipleChoiceQuestion.h"
#include "MultipleChoiceQuestionView.h"
#include "MultipleChoiceQuestionState.h"

using namespace qp;
using namespace std;

struct MultipleChoiceQuestionViewTestFixture
{
public:
	MultipleChoiceQuestionViewTestFixture()
	:state(make_shared<CMultipleChoiceQuestionState>(make_shared<CMultipleChoiceQuestion>("What is the name of our planet?", 10, CGradedChoices({
			{ "Mercury", false },
			{ "Venus", false },
			{ "The Earth", true },
			{ "Mars", false }
	}))))
	{}
	
	CMultipleChoiceQuestionStatePtr state;
	ostringstream ostrm;
};

BOOST_FIXTURE_TEST_SUITE(MultipleChoiceQuestionViewTests, MultipleChoiceQuestionViewTestFixture)

BOOST_AUTO_TEST_CASE(MultipleChoiceQuestionViewShowsDescriptionAndDetails)
{
	istringstream istrm;
	shared_ptr<IQuestionView> questionView = make_shared<CMultipleChoiceQuestionView>(state, ostrm, istrm);
	questionView->Show();
	BOOST_CHECK_EQUAL(ostrm.str(), 
		"What is the name of our planet?\n"
		"( ) A. Mercury\n"
		"( ) B. Venus\n"
		"( ) C. The Earth\n"
		"( ) D. Mars\n"
		);
}

BOOST_AUTO_TEST_CASE(SubmitRequest)
{
	istringstream istrm("submit\n");
	shared_ptr<IQuestionView> view = make_shared<CMultipleChoiceQuestionView>(state, ostrm, istrm);
	bool submitRequested = false;
	view->DoOnSubmit([&submitRequested](){
		submitRequested = true;
	});
	BOOST_REQUIRE(view->HandleUserInput());
	BOOST_CHECK(submitRequested);
}

BOOST_AUTO_TEST_CASE(SkipRequest)
{
	istringstream istrm("skip\n");
	shared_ptr<IQuestionView> view = make_shared<CMultipleChoiceQuestionView>(state, ostrm, istrm);
	bool skipRequested = false;
	view->DoOnSkip([&skipRequested](){
		skipRequested = true;
	});
	BOOST_REQUIRE(view->HandleUserInput());
	BOOST_CHECK(skipRequested);
}

BOOST_AUTO_TEST_CASE(SkipSubmittedQuestionRequest)
{
	istringstream istrm("\n");
	state->Submit();
	shared_ptr<IQuestionView> view = make_shared<CMultipleChoiceQuestionView>(state, ostrm, istrm);
	bool skipRequested = false;
	view->DoOnSkip([&skipRequested](){
		skipRequested = true;
	});
	BOOST_REQUIRE(view->HandleUserInput());
	BOOST_CHECK(skipRequested);
}

BOOST_AUTO_TEST_CASE(AnswerRequestedByProcessingCorrectLetter)
{
	istringstream istrm("A\n");
	CMultipleChoiceQuestionView view(state, ostrm, istrm);
	view.Show();

	bool answerSelectedRequested = false;
	bool answerIndexIsCorrect = false;
	view.DoOnAnswerSelected([&answerSelectedRequested, &answerIndexIsCorrect](size_t answerIndex){
		answerIndexIsCorrect = (answerIndex == 0);
		answerSelectedRequested = true;
	});
	BOOST_REQUIRE(view.HandleUserInput());
	BOOST_CHECK(answerSelectedRequested);
	BOOST_CHECK(answerIndexIsCorrect);
	BOOST_CHECK_EQUAL(ostrm.str(),
		"What is the name of our planet?\n"
		"( ) A. Mercury\n"
		"( ) B. Venus\n"
		"( ) C. The Earth\n"
		"( ) D. Mars\n"
		"Choose an answer (A-D) or type 'submit' or 'skip': " 
		);
}

BOOST_AUTO_TEST_CASE(AnswerNotRequestedByProcessingIncorrectLetter)
{
		istringstream istrm("E\n");
		CMultipleChoiceQuestionView view(state, ostrm, istrm);
		bool answerSelectedRequested = false;
		view.DoOnAnswerSelected([&answerSelectedRequested](size_t answerIndex){
			answerIndex;
			answerSelectedRequested = true;
		});
		BOOST_REQUIRE(!view.HandleUserInput());
		BOOST_CHECK(!answerSelectedRequested);
		BOOST_CHECK_EQUAL(ostrm.str(), "Choose an answer (A-D) or type 'submit' or 'skip': "); 
}

BOOST_AUTO_TEST_CASE(AnswerNotRequestedByProcessingIncorrectString)
{
	istringstream istrm("answer\n");
	CMultipleChoiceQuestionView view(state, ostrm, istrm);
	bool answerSelectedRequested = false;
	view.DoOnAnswerSelected([&answerSelectedRequested](size_t answerIndex){
		answerIndex;
		answerSelectedRequested = true;
	});
	BOOST_REQUIRE(!view.HandleUserInput());
	BOOST_CHECK(!answerSelectedRequested);
	BOOST_CHECK_EQUAL(ostrm.str(), "Choose an answer (A-D) or type 'submit' or 'skip': ");
}



BOOST_AUTO_TEST_SUITE_END()