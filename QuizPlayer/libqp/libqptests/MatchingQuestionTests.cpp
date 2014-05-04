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

BOOST_AUTO_TEST_CASE(MatchingItemsConstruction)
{
	CMatchingItems items;
	BOOST_REQUIRE_EQUAL(items.GetMatchedItemsCount(), 0u);
	BOOST_REQUIRE_EQUAL(items.GetExtraItemsCount(), 0u);
}

BOOST_AUTO_TEST_CASE(AddMatchedItemsToCollection)
{
	CMatchingItems items;
	
	BOOST_REQUIRE_NO_THROW(items.AddMatchedItems("1", "one"));
	BOOST_REQUIRE_EQUAL(items.GetMatchedItemsCount(), 1u);
	CMatchingItems::MatchedItems firstMatch = items.GetMatchedItems(0);
	BOOST_REQUIRE_EQUAL(firstMatch.first, "1");
	BOOST_REQUIRE_EQUAL(firstMatch.second, "one");
	BOOST_REQUIRE_THROW(items.GetMatchedItems(1), out_of_range);

	BOOST_REQUIRE_THROW(items.AddMatchedItems("1", "different"), invalid_argument);
	BOOST_REQUIRE_EQUAL(items.GetMatchedItemsCount(), 1u);

	BOOST_REQUIRE_THROW(items.AddMatchedItems("different", "one"), invalid_argument);
	BOOST_REQUIRE_EQUAL(items.GetMatchedItemsCount(), 1u);

	BOOST_REQUIRE_NO_THROW(items.AddExtraItem("extra"));
	BOOST_REQUIRE_THROW(items.AddMatchedItems("different", "extra"), invalid_argument);
	BOOST_REQUIRE_EQUAL(items.GetMatchedItemsCount(), 1u);
}

BOOST_AUTO_TEST_CASE(AddExtraItemToCollection)
{
	CMatchingItems items;
	BOOST_REQUIRE_NO_THROW(items.AddExtraItem("extra"));
	BOOST_REQUIRE_EQUAL(items.GetExtraItemsCount(), 1u);
	BOOST_REQUIRE_EQUAL(items.GetExtraItem(0), "extra");
	BOOST_REQUIRE_THROW(items.GetExtraItem(1), out_of_range);
	BOOST_REQUIRE_THROW(items.AddExtraItem("extra"), invalid_argument);

	BOOST_REQUIRE_NO_THROW(items.AddMatchedItems("1", "one"));
	BOOST_REQUIRE_THROW(items.AddExtraItem("one"), invalid_argument);
}

BOOST_AUTO_TEST_CASE(GettingLeftMatchedItems)
{
	CMatchingItems items;
	BOOST_CHECK(items.GetLeftMatchedItems().empty());

	items.AddMatchedItems("1", "one");
	auto leftItems = items.GetLeftMatchedItems();
	BOOST_REQUIRE_EQUAL(leftItems.size(), 1u);
	BOOST_REQUIRE_EQUAL(leftItems[0], "1");

	items.AddExtraItem("extra");
	leftItems = items.GetLeftMatchedItems();
	BOOST_REQUIRE_EQUAL(leftItems.size(), 1u);
	BOOST_REQUIRE_EQUAL(leftItems[0], "1");
}

BOOST_AUTO_TEST_CASE(GettingRightMatchedItems)
{
	CMatchingItems items;
	BOOST_CHECK(items.GetRightMatchedItems().empty());

	items.AddMatchedItems("1", "one");
	items.AddMatchedItems("2", "two");
	auto rightItems = items.GetRightMatchedItems();
	BOOST_REQUIRE_EQUAL(rightItems.size(), 2u);
	BOOST_REQUIRE_EQUAL(rightItems[0], "one");
	BOOST_REQUIRE_EQUAL(rightItems[1], "two");

	items.AddExtraItem("extra");
	rightItems = items.GetRightMatchedItems();
	BOOST_REQUIRE_EQUAL(rightItems.size(), 3u);
	BOOST_REQUIRE_EQUAL(rightItems[0], "one");
	BOOST_REQUIRE_EQUAL(rightItems[1], "two");
	BOOST_REQUIRE_EQUAL(rightItems[2], "extra");
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
	CMatchingItems items1;
	items1.AddMatchedItems("1", "one");
	items1.AddExtraItem("extra");
	question.SetPairChoices(items1);

	CMatchingItems items2 = question.GetPairChoices();
	auto matchedItems = items2.GetMatchedItems(0);
	BOOST_REQUIRE_EQUAL(items1.GetMatchedItemsCount(), items2.GetMatchedItemsCount());
	BOOST_REQUIRE_EQUAL(items1.GetExtraItemsCount(), items2.GetExtraItemsCount());
	
	BOOST_REQUIRE_EQUAL(items1.GetMatchedItems(0).first, items2.GetMatchedItems(0).first);
	BOOST_REQUIRE_EQUAL(items1.GetMatchedItems(0).second, items2.GetMatchedItems(0).second);
	BOOST_REQUIRE_EQUAL(items1.GetExtraItem(0), items2.GetExtraItem(0));
}

BOOST_AUTO_TEST_SUITE_END()
