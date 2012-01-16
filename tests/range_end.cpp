#include <typeinfo>
#include <vector>
#include "tests.h"
#include "../include/pps/range/end.h"

using pps::range::end;

int main()
{
	// Library doesn't handle that for the momment.
//	int t1[1];
//	PPS_TESTS_ASSERT(typeid(end(t1)) == typeid(int*));

	// Static assert, ok.
//	int t2[] = {1, 2, 3};
//	PPS_TESTS_ASSERT(typeid(end(t2)) == typeid(int*));

	// Static assert, ok.
//	int* t3 = t2;
//	PPS_TESTS_ASSERT(typeid(end(t3)) == typeid(int*));

	std::vector<int> t4;
	PPS_TESTS_ASSERT(typeid(end(t4)) == typeid(std::vector<int>::iterator));
	PPS_TESTS_ASSERT(end(t4) == t4.end());

	return 0;
}
