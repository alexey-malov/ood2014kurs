#include "stdafx.h"
#include "utils.h"

BOOST_AUTO_TEST_SUITE(UtilsTestSuite)

using namespace qp;

BOOST_AUTO_TEST_CASE(RemoveExtraSpacesTests)
{
	BOOST_REQUIRE_EQUAL(RemoveExtraSpaces(""), "");
	BOOST_REQUIRE_EQUAL(RemoveExtraSpaces("a"), "a");
	BOOST_REQUIRE_EQUAL(RemoveExtraSpaces(" a  b"), "a b");
	BOOST_REQUIRE_EQUAL(RemoveExtraSpaces("    example  of   extra blanks   "), "example of extra blanks");
	BOOST_REQUIRE_EQUAL(RemoveExtraSpaces("   "), "");
}

BOOST_AUTO_TEST_SUITE_END()