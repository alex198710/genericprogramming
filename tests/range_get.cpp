#include "tests.h"#include <vector>#include <list>int main(){	std::vector<std::list<double*>> t1;	std::list<double*> t11;	double t111[] = {0.5, 6.7, 9.4};	double t112[] = {1.7, 5.6, 1.1};	t11.push_back(t111);	t11.push_back(t112);	t1.push_back(t11);	return 0;}