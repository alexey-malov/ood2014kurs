#include "stdafx.h"
#include "SequenceQuestion.h"
#include "utils.h"

BOOST_AUTO_TEST_SUITE(SequenceQuestionTests)

using namespace qp;
using namespace std;
using Sequence = CSequenceQuestion::Sequence;

BOOST_AUTO_TEST_CASE(CorrectConstruction)
{
	{
		// test constructor
		Sequence sequence = { "one", "two", "three" };
		CSequenceQuestion sequenceQuestion("another test question", 1.0, sequence);

		BOOST_REQUIRE_EQUAL(sequenceQuestion.GetDescription(), "another test question");
		BOOST_REQUIRE_CLOSE(sequenceQuestion.GetScore(), 1.0, 0.0001);
		BOOST_REQUIRE_EQUAL_COLLECTIONS(sequence.begin(), sequence.end(), sequenceQuestion.GetSequence().begin(), sequenceQuestion.GetSequence().end());
	}

	{
		// test matching items count exception
		Sequence sequence = { "one", "two" };
		BOOST_REQUIRE_THROW(CSequenceQuestion sequenceQuestion("another test question", 1.0, sequence), invalid_argument)
	}

	{
		// test empty matching item exception
		Sequence sequence = { "one", "", "three" };
		BOOST_REQUIRE_THROW(CSequenceQuestion sequenceQuestion("another test question", 1.0, sequence), invalid_argument)
	}

	{
		// test duplicates in matching items exception
		Sequence sequence = { "one", "two", "one" };
		BOOST_REQUIRE_THROW(CSequenceQuestion sequenceQuestion("another test question", 1.0, sequence), invalid_argument)
	}
}

BOOST_AUTO_TEST_SUITE_END()
