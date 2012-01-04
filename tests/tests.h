#ifndef PPS_TESTS_H
#define PPS_TESTS_H

#define PPS_TESTS_ASSERT(expression) pps::tests::assertTrue(expression, #expression)

namespace pps {
namespace tests {

void assertTrue(bool p_condition, const char* p_message);
void assertFalse(bool p_condition, const char* p_message);
template<class T> void assertEqual(const T& p_first, const T& p_second, const char* p_message);
template<class T> void assertNotEqual(const T& p_first, const T& p_second, const char* p_message);
template<class T> void assertClose(const T& p_first, const T& p_second, const T& p_precision, const char* p_message);
template<class T> void assertNotClose(const T& p_first, const T& p_second, const T& p_precision, const char* p_message);

}}

#include <iostream>

namespace pps {
namespace tests {

inline void assertTrue(bool p_condition, const char* p_message)
{
	std::cout << "Asserting " << p_message << " : " << ((p_condition) ? "OK" : "ERROR") << std::endl;
}

inline void assertFalse(bool p_condition, const char* p_message)
{
	assertTrue(!p_condition, p_message);
}

template<class T>
inline void assertEqual(const T& p_first, const T& p_second, const char* p_message)
{
	assertTrue(p_first == p_second, p_message);
}

template<class T>
inline void assertNotEqual(const T& p_first, const T& p_second, const char* p_message)
{
	assertTrue(p_first != p_second, p_message);
}

template<class T>
inline void assertClose(const T& p_first, const T& p_second, const T& p_precision, const char* p_message)
{
	assertTrue(abs(p_first - p_second) < p_precision, p_message);
}

template<class T>
inline void assertNotClose(const T& p_first, const T& p_second, const T& p_precision, const char* p_message)
{
	assertTrue(abs(p_first - p_second) > p_precision, p_message);
}

}}

#endif
