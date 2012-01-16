#ifndef PPS_MULTI_ARRAY_TRAITS_ITERATOR_H
#define PPS_MULTI_ARRAY_TRAITS_ITERATOR_H

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>

namespace pps {
namespace multi_array {

template<class T>
struct traits_iterator
{
	typedef const T constIterator;
	typedef T iterator;
};

template<class T>
struct traits_iterator<T*>
{
	typedef typename traits_iterator<T>::constIterator* constIterator;
	typedef typename traits_iterator<T>::iterator* iterator;
};

/*
	-------------------------------------------------
		Specializations to support STL containers
	-------------------------------------------------
*/

template<class T>
struct traits_iterator<std::vector<T>>
{
	typedef typename std::vector<T>::const_iterator constIterator;
	typedef typename std::vector<T>::iterator iterator;
};

template<class T>
struct traits_iterator<std::deque<T>>
{
	typedef typename std::deque<T>::const_iterator constIterator;
	typedef typename std::deque<T>::iterator iterator;
};

template<class T>
struct traits_iterator<std::list<T>>
{
	typedef typename std::list<T>::const_iterator constIterator;
	typedef typename std::list<T>::iterator iterator;
};

template<class T>
struct traits_iterator<std::set<T>>
{
	typedef typename std::set<T>::const_iterator constIterator;
	typedef typename std::set<T>::iterator iterator;
};

template<class T>
struct traits_iterator<std::multiset<T>>
{
	typedef typename std::multiset<T>::const_iterator constIterator;
	typedef typename std::multiset<T>::iterator iterator;
};

template<class Key, class T>
struct traits_iterator<std::map<Key, T>>
{
	typedef typename std::map<Key, T>::const_iterator constIterator;
	typedef typename std::map<Key, T>::iterator iterator;
};

template<class Key, class T>
struct traits_iterator<std::multimap<Key, T>>
{
	typedef typename std::multimap<Key, T>::const_iterator constIterator;
	typedef typename std::multimap<Key, T>::iterator iterator;
};

}}

#endif
