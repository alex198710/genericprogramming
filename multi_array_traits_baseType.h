#ifndef PPS_MULTI_ARRAY_TRAITS_BASE_TYPE_H
#define PPS_MULTI_ARRAY_TRAITS_BASE_TYPE_H

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>

namespace pps {
namespace multi_array {

template<class T>
struct traits_baseType
{
	typedef T baseType;
};

template<class T>
struct traits_baseType<T*>
{
	typedef typename traits_baseType<T>::baseType baseType;
};

/*
	-------------------------------------------------
		Specializations to support STL containers
	-------------------------------------------------
*/

template<class T>
struct traits_baseType<std::vector<T>>
{
	typedef typename traits_baseType<T>::baseType baseType;
};

template<class T>
struct traits_baseType<std::deque<T>>
{
	typedef typename traits_baseType<T>::baseType baseType;
};

template<class T>
struct traits_baseType<std::list<T>>
{
	typedef typename traits_baseType<T>::baseType baseType;
};

template<class T>
struct traits_baseType<std::set<T>>
{
	typedef typename traits_baseType<T>::baseType baseType;
};

template<class T>
struct traits_baseType<std::multiset<T>>
{
	typedef typename traits_baseType<T>::baseType baseType;
};

template<class Key, class T>
struct traits_baseType<std::map<Key, T>>
{
	typedef typename traits_baseType<T>::baseType baseType;
};

template<class Key, class T>
struct traits_baseType<std::multimap<Key, T>>
{
	typedef typename traits_baseType<T>::baseType baseType;
};

}}

#endif
