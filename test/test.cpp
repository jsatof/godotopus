#define BOOST_TEST_MODULE GodotOpus
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <thing.h>

BOOST_AUTO_TEST_SUITE(GodotOpus)

BOOST_AUTO_TEST_CASE(test1) {
	std::string str = thing();
	BOOST_CHECK(str == "hello\n");
}


BOOST_AUTO_TEST_SUITE_END()

