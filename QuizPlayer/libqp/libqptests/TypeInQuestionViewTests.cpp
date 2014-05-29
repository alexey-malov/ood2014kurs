#include "stdafx.h"

#include "TypeInQuestion.h"
#include "TypeInQuestionView.h"
#include "TypeInQuestionState.h"

using namespace qp;
using namespace std;

BOOST_AUTO_TEST_SUITE(TypeInQuestionViewTests)

BOOST_AUTO_TEST_CASE(TypeInQuestionViewShowsDescription)
{
	string description = "Description";
	set<string> answers = {"First answer", "Second answer"};
	auto question = make_shared<CTypeInQuestion>(description, answers, 10);
	auto state = make_shared<CTypeInQuestionState>(question);

	ostringstream ostrm;
	istringstream istrm;
	CTypeInQuestionView view(state, ostrm, istrm);
	view.Show();
	BOOST_CHECK_EQUAL(ostrm.str(), description + "\n");
}

BOOST_AUTO_TEST_SUITE_END()
