#ifndef PPS_RANGE_INDEXES_H
#define PPS_RANGE_INDEXES_H

#include <list>
#include "traits.h"

namespace pps {
namespace range {

class indexes
{
	public:
		typedef typename std::list<std::size_t>::const_iterator constIterator;
		typedef typename std::list<std::size_t>::iterator iterator;

	private:
		std::list<std::size_t> m_data;

	public:
		indexes();
		indexes(const indexes& p_indexes);

		template<class InputIterator>
		indexes(InputIterator p_first, InputIterator p_last);

		indexes& operator=(const indexes& p_indexes);

		constIterator begin() const;
		iterator begin();
		constIterator end() const;
		iterator end();

		indexes& operator[](std::size_t p_index);
};

// ---- Extending library to support indexes as a range

template<>
struct traits<indexes>
	: traits<std::list<std::size_t>>
{
};

typename traits<indexes>::constIterator begin(const indexes& p_range);
typename traits<indexes>::iterator begin(indexes& p_range);
typename traits<indexes>::constIterator end(const indexes& p_range);
typename traits<indexes>::iterator end(indexes& p_range);

}}

namespace pps {
namespace range {

template<class InputIterator>
indexes::indexes(InputIterator p_first, InputIterator p_last)
: m_data(p_first, p_last)
{
}

}}

#endif
