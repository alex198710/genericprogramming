#include <typeinfo>#include <vector>#include "tests.h"#include "../multi_array_traits_baseType.h"using pps::multi_array::traits_baseType;int main(){	PPS_TESTS_ASSERT(typeid(traits_baseType<int>::baseType) == typeid(int));	PPS_TESTS_ASSERT(typeid(traits_baseType<int*>::baseType) == typeid(int));	PPS_TESTS_ASSERT(typeid(traits_baseType<int**>::baseType) == typeid(int));	PPS_TESTS_ASSERT(typeid(traits_baseType<double***>::baseType) == typeid(double));	PPS_TESTS_ASSERT(typeid(traits_baseType<std::vector<double>>::baseType) == typeid(double));	PPS_TESTS_ASSERT(typeid(traits_baseType<std::vector<std::vector<double>>>::baseType) == typeid(double));	PPS_TESTS_ASSERT(typeid(traits_baseType<std::vector<std::vector<double>*>>::baseType) == typeid(double));	return 0;}