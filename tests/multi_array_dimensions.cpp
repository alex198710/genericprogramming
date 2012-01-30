#include "../multi_array_dimensions.h"
#include "tests.h"

using pps::multi_array::dimensions;

int main()
{
	dimensions d1;
	PPS_TESTS_ASSERT(d1.begin() == d1.end());

	d1[3][4];
	dimensions::iterator itD1(d1.begin());
	PPS_TESTS_ASSERT(*itD1++ == 3);
	PPS_TESTS_ASSERT(*itD1++ == 4);
	PPS_TESTS_ASSERT(itD1 == d1.end());

	dimensions d2(d1);
	dimensions::iterator itD2(d2.begin());
	PPS_TESTS_ASSERT(*itD2++ == 3);
	PPS_TESTS_ASSERT(*itD2++ == 4);
	PPS_TESTS_ASSERT(itD2 == d2.end());

	dimensions d3 = d1;
	dimensions::iterator itD3(d3.begin());
	PPS_TESTS_ASSERT(*itD3++ == 3);
	PPS_TESTS_ASSERT(*itD3++ == 4);
	PPS_TESTS_ASSERT(itD3 == d3.end());

	dimensions d4 = dimensions()[1][2];
	dimensions::iterator itD4(d4.begin());
	PPS_TESTS_ASSERT(*itD4++ == 1);
	PPS_TESTS_ASSERT(*itD4++ == 2);
	PPS_TESTS_ASSERT(itD4 == d4.end());

	return 0;
}
