#include <vector>#include "tests.h"#include "../multi_array_traits_depth.h"using pps::multi_array::traits_depth;int main(){	PPS_TESTS_ASSERT(traits_depth<int>::depth == 0);	PPS_TESTS_ASSERT(traits_depth<int*>::depth == 1);	PPS_TESTS_ASSERT(traits_depth<int**>::depth == 2);	PPS_TESTS_ASSERT(traits_depth<double***>::depth == 3);	PPS_TESTS_ASSERT(traits_depth<std::vector<int>>::depth == 1);	PPS_TESTS_ASSERT(traits_depth<std::vector<double***>>::depth == 4);	return 0;}