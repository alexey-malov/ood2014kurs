#include "stdafx.h"

#include "TypeInQuestion.h"
#include "TypeInQuestionView.h"
#include "TypeInQuestionState.h"

using namespace qp;
using namespace std;

set<string> TypeInAnswers = {"First answer", "Second answer"};

struct TypeInQuestionStateFixture
{
	TypeInQuestionStateFixture()
	:state(make_shared<CTypeInQuestionState>(make_shared<CTypeInQuestion>("Question description", TypeInAnswers, 10)))
	{
	}
	CTypeInQuestionStatePtr state;
	ostringstream ostrm;
};

BOOST_FIXTURE_TEST_SUITE(TypeInQuestionViewTests, TypeInQuestionStateFixture)

BOOST_AUTO_TEST_CASE(TypeInQuestionViewShowsDescription)
{
	istringstream istrm;
	shared_ptr<IQuestionView> questionView = make_shared<CTypeInQuestionView>(state, ostrm, istrm);
	questionView->Show();
	BOOST_CHECK_EQUAL(ostrm.str(), "Question description\n");
}

BOOST_AUTO_TEST_CASE(SubmitRequest)
{
	istringstream istrm("submit\n");
	shared_ptr<IQuestionView> view = make_shared<CTypeInQuestionView>(state, ostrm, istrm);
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
	shared_ptr<IQuestionView> view = make_shared<CTypeInQuestionView>(state, ostrm, istrm);
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
	shared_ptr<IQuestionView> view = make_shared<CTypeInQuestionView>(state, ostrm, istrm);
	bool skipRequested = false;
	view->DoOnSkip([&skipRequested](){
		skipRequested = true;
	});
	BOOST_REQUIRE(view->HandleUserInput());
	BOOST_CHECK(skipRequested);
}

BOOST_AUTO_TEST_CASE(EnterEmptyUserAnswerNoSubmit)
{
	string answerEntered = "answer";
	istringstream istrm("\n");
	CTypeInQuestionView view(state, ostrm, istrm);
	
	view.DoOnAnswerEntered([&answerEntered](string const& answer){
		answerEntered = answer;
	});

	BOOST_REQUIRE(!view.HandleUserInput());
	BOOST_CHECK_EQUAL(answerEntered, "answer");
}

BOOST_AUTO_TEST_CASE(EnterNotEmptyUserAnswer)
{
	string answerEntered = "First answer";
	istringstream istrm("Second answer\n");
	CTypeInQuestionView view(state, ostrm, istrm);
	
	view.DoOnAnswerEntered([&answerEntered](string const& answer){
	answerEntered = answer;
	});
	BOOST_REQUIRE(view.HandleUserInput());
	BOOST_CHECK_EQUAL(answerEntered, "Second answer");
}

BOOST_AUTO_TEST_SUITE_END()
