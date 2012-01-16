#ifndef PPS_MULTI_ARRAY_TRAITS_DEPTH_H
#define PPS_MULTI_ARRAY_TRAITS_DEPTH_H

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>

namespace pps {
namespace multi_array {

template<class T, std::size_t N = 0>
struct traits_depth
{
	static const std::size_t depth = N;
};

template<class T, std::size_t N>
struct traits_depth<T*, N>
{
	static const std::size_t depth = traits_depth<T, N + 1>::depth;
};

/*
	-------------------------------------------------
		Specializations to support STL containers
	-------------------------------------------------
*/

template<class T, std::size_t N>
struct traits_depth<std::vector<T>, N>
{
	static const std::size_t depth = traits_depth<T, N + 1>::depth;
};

template<class T, std::size_t N>
struct traits_depth<std::deque<T>, N>
{
	static const std::size_t depth = traits_depth<T, N + 1>::depth;
};

template<class T, std::size_t N>
struct traits_depth<std::list<T>, N>
{
	static const std::size_t depth = traits_depth<T, N + 1>::depth;
};

template<class T, std::size_t N>
struct traits_depth<std::set<T>, N>
{
	static const std::size_t depth = traits_depth<T, N + 1>::depth;
};

template<class T, std::size_t N>
struct traits_depth<std::multiset<T>, N>
{
	static const std::size_t depth = traits_depth<T, N + 1>::depth;
};

template<class Key, class T, std::size_t N>
struct traits_depth<std::map<Key, T>, N>
{
	static const std::size_t depth = traits_depth<T, N + 1>::depth;
};

template<class Key, class T, std::size_t N>
struct traits_depth<std::multimap<Key, T>, N>
{
	static const std::size_t depth = traits_depth<T, N + 1>::depth;
};

}}

#endif
