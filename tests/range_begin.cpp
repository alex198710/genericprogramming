#include <typeinfo>#include <vector>#include "tests.h"#include "../include/pps/range/begin.h"using pps::range::begin;int main(){	toto<int> toto;	toto.myMethod();	int t1[1];	PPS_TESTS_ASSERT(typeid(begin(t1)) == typeid(int*));	// Static assert, ok.	int t2[] = {1, 2, 3};	PPS_TESTS_ASSERT(typeid(begin(t2)) == typeid(int*));	// Static assert, ok.	int* t3 = t2;	PPS_TESTS_ASSERT(typeid(begin(t3)) == typeid(int*));	std::vector<int> t4;	t4.push_back(3);	t4.push_back(5);	t4.push_back(7);	PPS_TESTS_ASSERT(typeid(begin(t4)) == typeid(std::vector<int>::iterator));	PPS_TESTS_ASSERT(begin(t4) == t4.begin());	return 0;}