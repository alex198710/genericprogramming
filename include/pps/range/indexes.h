#ifndef PPS_RANGE_INDEXES_H
#define PPS_RANGE_INDEXES_H

#include <list>
#include "traits.h"

namespace pps {
namespace range {

template<int N>
class indexes
{
	private:
		std::list<std::size_t> m_data;

	public:
		indexes();
		indexes(const indexes<N>& p_indexes);

		indexes<N>& operator=(const indexes<N>& p_indexes);

		std::list<std::size_t>::const_iterator begin() const;
		std::list<std::size_t>::iterator begin();
		std::list<std::size_t>::const_iterator end() const;
		std::list<std::size_t>::iterator end();

		indexes<N>& operator[](std::size_t p_index);
};

}}

namespace pps {
namespace range {

template<int N>
indexes<N>::indexes()
{
}

template<int N>
indexes<N>::indexes(const indexes& p_indexes)
: m_data(p_indexes.m_data)
{
}

template<int N>
indexes<N>& indexes<N>::operator=(const indexes& p_indexes)
{
	if(&p_indexes == this)
		return *this;

	m_data = p_indexes.m_data;

	return *this;
}

template<int N>
std::list<std::size_t>::const_iterator indexes<N>::begin() const
{
	return m_data.begin();
}

template<int N>
std::list<std::size_t>::iterator indexes<N>::begin()
{
	return m_data.begin();
}

template<int N>
std::list<std::size_t>::const_iterator indexes<N>::end() const
{
	return m_data.end();
}

template<int N>
std::list<std::size_t>::iterator indexes<N>::end()
{
	return m_data.end();
}

template<int N>
indexes<N>& indexes<N>::operator[](std::size_t p_index)
{
	m_data.push_back(p_index);
	return *this;
}

// ---- Extending library to support indexes as a range

template<int N>
struct traits<indexes<N>>
	: traits<std::list<std::size_t>>
{
};

template<int N>
typename traits<std::list<std::size_t>>::constIterator
begin(const indexes<N>& p_range)
{
	return p_range.begin();
}

template<int N>
typename traits<std::list<std::size_t>>::iterator
begin(indexes<N>& p_range)
{
	return p_range.begin();
}

template<int N>
typename traits<std::list<std::size_t>>::constIterator
end(const indexes<N>& p_range)
{
	return p_range.end();
}

template<int N>
typename traits<std::list<std::size_t>>::iterator
end(indexes<N>& p_range)
{
	return p_range.end();
}

}}

#endif
