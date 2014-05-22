#include "stdafx.h"
#include "SequenceQuestion.h"
#include "utils.h"

BOOST_AUTO_TEST_SUITE(SequenceQuestionTests)

using namespace qp;
using namespace std;
using MatchedItems = CSequenceQuestion::MatchedItems;

BOOST_AUTO_TEST_CASE(CorrectConstruction)
{
	{
		// test constructor
		MatchedItems matchedItems = { "one", "two", "three" };
		CSequenceQuestion sq("another test question", 1.0, matchedItems);

		BOOST_REQUIRE_EQUAL(sq.GetDescription(), "another test question");
		BOOST_REQUIRE_CLOSE(sq.GetScore(), 1.0, 0.0001);
		BOOST_REQUIRE_EQUAL_COLLECTIONS(matchedItems.begin(), matchedItems.end(), sq.GetMatchedItems().begin(), sq.GetMatchedItems().end());
	}

	{
		// test matching items count exception
		MatchedItems matchedItems = { "one", "two" };
		BOOST_REQUIRE_THROW(CSequenceQuestion sq("another test question", 1.0, matchedItems), invalid_argument)
	}

	{
		// test empty matching item exception
		MatchedItems matchedItems = { "one", "", "three" };
		BOOST_REQUIRE_THROW(CSequenceQuestion sq("another test question", 1.0, matchedItems), invalid_argument)
	}

	{
		// test duplicates in matching items exception
		MatchedItems matchedItems = { "one", "two", "one" };
		BOOST_REQUIRE_THROW(CSequenceQuestion sq("another test question", 1.0, matchedItems), invalid_argument)
	}
}

BOOST_AUTO_TEST_SUITE_END()
