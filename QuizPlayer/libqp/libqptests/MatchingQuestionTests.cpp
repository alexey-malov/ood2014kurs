#include "stdafx.h"
#include "MatchingQuestion.h"

BOOST_AUTO_TEST_SUITE(MatchingQuestionTests)

using namespace qp;
using namespace std;

BOOST_AUTO_TEST_CASE(Construction)
{
	CMatchingQuestion mq("Question description");
	BOOST_REQUIRE_EQUAL(mq.GetDescription(), "Question description");
	BOOST_REQUIRE_CLOSE(mq.GetScore(), 0.0, 0.0001);
}

BOOST_AUTO_TEST_CASE(MatchingPairsCollection)
{
	CMatchingPairs mp;
	BOOST_REQUIRE_EQUAL(mp.GetPairsCount(), 0u);

	mp.AddPair("1", "one");
	BOOST_REQUIRE_EQUAL(mp.GetPairsCount(), 1u);

	{
		MatchingPair pair = mp.GetMatchingPair(0);
		BOOST_REQUIRE(pair.leftItem);
		BOOST_CHECK_EQUAL(*pair.leftItem, "1");
		BOOST_REQUIRE(pair.rightItem);
		BOOST_CHECK_EQUAL(*pair.rightItem, "one");
	}

	mp.AddPair("extra");
	BOOST_CHECK_EQUAL(mp.GetPairsCount(), 2u);
	BOOST_REQUIRE_THROW(mp.GetMatchingPair(2), out_of_range);

	{
		MatchingPair pair = mp.GetMatchingPair(1);
		BOOST_REQUIRE(!pair.leftItem);
		BOOST_REQUIRE(pair.rightItem);
		BOOST_REQUIRE_EQUAL(*pair.rightItem, "extra");
	}
}

BOOST_AUTO_TEST_CASE(QuestionConstruction)
{
	CMatchingQuestion question("description");
	BOOST_REQUIRE_EQUAL(question.GetDescription(), "description");
	BOOST_REQUIRE_CLOSE(question.GetScore(), 0.0, 0.0001);
}

BOOST_AUTO_TEST_CASE(PairChoicesAccessors)
{
	CMatchingQuestion question("description");
	CMatchingPairs pairChoices;
	pairChoices.AddPair("1", "one");
	pairChoices.AddPair("extra");
	question.SetPairChoices(pairChoices);

	CMatchingPairs pairChoices2 = question.GetPairChoices();
	BOOST_REQUIRE_EQUAL(pairChoices.GetPairsCount(), pairChoices2.GetPairsCount());

	BOOST_REQUIRE_EQUAL(pairChoices.GetMatchingPair(0).leftItem, pairChoices2.GetMatchingPair(0).leftItem);
	BOOST_REQUIRE_EQUAL(pairChoices.GetMatchingPair(0).rightItem, pairChoices2.GetMatchingPair(0).rightItem);
	BOOST_REQUIRE_EQUAL(pairChoices.GetMatchingPair(1).leftItem, pairChoices2.GetMatchingPair(1).leftItem);
	BOOST_REQUIRE_EQUAL(pairChoices.GetMatchingPair(1).rightItem, pairChoices2.GetMatchingPair(1).rightItem);
}

BOOST_AUTO_TEST_SUITE_END()
