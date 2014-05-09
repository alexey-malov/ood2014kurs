#include "stdafx.h"
#include "MatchingQuestion.h"
#include "utils.h"

BOOST_AUTO_TEST_SUITE(MatchingQuestionTests)

using namespace qp;
using namespace std;
using MatchedItems = CMatchingQuestion::MatchedItems;
using StandaloneItems = CMatchingQuestion::StandaloneItems;
using MatchedItemsCollection = CMatchingQuestion::MatchedItemsCollection;

BOOST_AUTO_TEST_CASE(CorrectConstruction)
{
	{
		CMatchingQuestion mq("Question description");
		BOOST_REQUIRE_EQUAL(mq.GetDescription(), "Question description");
		BOOST_REQUIRE_CLOSE(mq.GetScore(), 0.0, 0.0001);
		BOOST_CHECK(mq.GetMatchedItems().empty());
		BOOST_CHECK(mq.GetExtraItems().empty());
	}

	MatchedItemsCollection matchedItems = { MatchedItems("1", "one"), MatchedItems("2", "two") };

	{
		CMatchingQuestion mq("Question description", 10, matchedItems);
		BOOST_CHECK_EQUAL(mq.GetMatchedItemsCount(), matchedItems.size());
		BOOST_CHECK(mq.GetExtraItems().empty());

		auto tmpMatchedItems = mq.GetMatchedItems();
		BOOST_CHECK_EQUAL(matchedItems[0].first, tmpMatchedItems[0].first);
		BOOST_CHECK_EQUAL(matchedItems[0].second, tmpMatchedItems[0].second);
		BOOST_CHECK_EQUAL(matchedItems[1].first, tmpMatchedItems[1].first);
		BOOST_CHECK_EQUAL(matchedItems[1].second, tmpMatchedItems[1].second);
	}

	StandaloneItems extraItems = { "extra" };
	{
		CMatchingQuestion mq("Question description", 10, matchedItems, extraItems);
		BOOST_CHECK_EQUAL(mq.GetMatchedItemsCount(), matchedItems.size());
		BOOST_CHECK_EQUAL(mq.GetExtraItemsCount(), extraItems.size());

		auto tmpExtraItems = mq.GetExtraItems();
		BOOST_CHECK_EQUAL(extraItems[0], tmpExtraItems[0]);
	}
}

BOOST_AUTO_TEST_CASE(IncorrectConstruction)
{
	MatchedItemsCollection matchedItems = { MatchedItems("1", "one"), MatchedItems("2", "two") };
	StandaloneItems extraItems = { "extra" };

	{
		extraItems.emplace_back("extra");
		BOOST_REQUIRE_THROW(CMatchingQuestion mq("description", 10, matchedItems, extraItems), invalid_argument);
	}

	{
		matchedItems.emplace_back("0", "extra");
		BOOST_REQUIRE_THROW(CMatchingQuestion mq("description", 10, matchedItems, extraItems), invalid_argument);
	}

	{
		matchedItems.emplace_back("1", "");
		BOOST_REQUIRE_THROW(CMatchingQuestion mq("description", 10, matchedItems, extraItems), invalid_argument);
	}

	{
		matchedItems.emplace_back("", "one");
		BOOST_REQUIRE_THROW(CMatchingQuestion mq("description", 10, matchedItems, extraItems), invalid_argument);
	}
}

BOOST_AUTO_TEST_CASE(GetLeftItems)
{
	CMatchingQuestion mq0("Question description");
	BOOST_CHECK(mq0.GetLeftMatchingItems().empty());
	
	MatchedItemsCollection matchedItems = { MatchedItems("1", "one"), MatchedItems("2", "two") };
	StandaloneItems extraItems = { "extra" };

	CMatchingQuestion mq("Question description", 10, matchedItems, extraItems);
	StandaloneItems leftItems = mq.GetLeftMatchingItems();
	BOOST_CHECK_EQUAL(leftItems[0], "1");
	BOOST_CHECK_EQUAL(leftItems[1], "2");
}

BOOST_AUTO_TEST_CASE(GetRightItems)
{
	CMatchingQuestion mq0("Question description");
	BOOST_CHECK(mq0.GetRightMatchingItems().empty());

	MatchedItemsCollection matchedItems = { MatchedItems("1", "one"), MatchedItems("2", "two") };
	StandaloneItems extraItems = { "extra" };
	CMatchingQuestion mq("Question description", 10, matchedItems, extraItems);

	StandaloneItems rightItems = mq.GetRightMatchingItems();
	BOOST_CHECK_EQUAL(rightItems[0], "one");
	BOOST_CHECK_EQUAL(rightItems[1], "two");
	BOOST_CHECK_EQUAL(rightItems[2], "extra");
}

BOOST_AUTO_TEST_SUITE_END()
