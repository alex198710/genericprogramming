#include "tests.h"#include <vector>#include <list>#include "../include/pps/range/get.h"#include "../include/pps/range/indexes.h"using pps::range::get;using pps::range::indexes;int main(){	std::vector<std::list<int>> t1;	std::list<int> t11;	t11.push_back(34);	t11.push_back(52);	t1.push_back(t11);	std::list<int> t12;	t12.push_back(2);	t12.push_back(19);	t1.push_back(t12);	PPS_TESTS_ASSERT(get<2>(t1, indexes()[0][0]) == 34);	PPS_TESTS_ASSERT(get<2>(t1, indexes()[1][1]) == 52);	return 0;}