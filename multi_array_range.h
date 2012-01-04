#ifndef PPS_MULTI_ARRAY_RANGE_H
#define PPS_MULTI_ARRAY_RANGE_H

#include "multi_array_traits_iterator.h"

namespace pps {
namespace multi_array {

template<class T>
class range
{
	typedef typename traits_iterator<T>::type iterator;

	private:
		iterator m_begin;
		iterator m_end;

	public:
		range(const iterator& p_begin, const iterator& p_end);
		range(const range<T>& p_range);

		range<T>& operator=(const range& p_range);

		inline const iterator& begin() const;
		inline const iterator& end() const;
};

}}

namespace pps {
namespace multi_array {

template<class T>
range<T>::range(const iterator& p_begin, const iterator& p_end)
: m_begin(p_begin), m_end(p_end)
{
}

template<class T>
range<T>::range(const range<T>& p_range)
: m_begin(p_range.m_begin), m_end(p_range.m_end)
{
}

template<class T>
range<T>& range<T>::operator=(const range<T>& p_range)
{
	if(&p_range == this)
		return *this;

	m_begin = p_range.m_begin;
	m_end = p_range.m_end;

	return *this;
}

template<class T>
inline const typename range<T>::iterator& range<T>::begin() const
{
	return m_begin;
}

template<class T>
inline const typename range<T>::iterator& range<T>::end() const
{
	return m_end;
}

}}

#endif
