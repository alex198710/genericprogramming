#ifndef PPS_MULTI_ARRAY_VIEW_H
#define PPS_MULTI_ARRAY_VIEW_H

#include <list>
#include "multi_array_range.h"

namespace pps {
namespace multi_array {

class view
	: public range<range<std::list<std::size_t>>>
{
	public:
		typedef typename range<std::list<std::size_t>>::constIterator constIterator;
		typedef typename range<std::list<std::size_t>>::iterator iterator;

	private:
		std::list<range<std::list<std::size_t>>> m_data;

	public:
		view();
		view(const view& p_view);

		view& operator=(const view& p_view);
		view& operator[](const range<>& p_range);

		inline virtual constIterator begin() const;
		inline virtual iterator begin();
		inline virtual constIterator end() const;
		inline virtual iterator end();
};

}}

#endif
