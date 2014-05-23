#include "stdafx.h"

#include "QuestionViewController.h"
#include "QuestionStateForTesting.h"
#include "QuestionForTest.h"
#include "QuestionView.h"

#include "MockQuestionView.h"

using namespace qp;
using namespace std;

BOOST_AUTO_TEST_SUITE(QuestionViewControllerTests)


BOOST_AUTO_TEST_CASE(SubmitRequestHandling)
{
	// TODO: устранить дублирование кода
	struct TestQuestionView : public CQuestionView
	{
		TestQuestionView(const CQuestionStatePtr & questionState, std::ostream & outputStream, std::istream & inputStream)
			:CQuestionView(questionState, outputStream, inputStream)
		{}

		void ShowDetails() override
		{
		}


	};

	auto q = make_shared<CQuestionForTest>("descr", 10);
	auto qs = make_shared<CQuestionStateForTesting>(q);
	istringstream istrm;
	ostringstream ostrm;
	auto qv = make_shared<CMockQuestionView>();
	CQuestionViewController qvc(qs, qv);
	BOOST_REQUIRE_NO_THROW(qv->onSubmit());
	BOOST_REQUIRE(qs->Submitted());
}

BOOST_AUTO_TEST_SUITE_END()