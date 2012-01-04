#ifndef PPS_MULTI_ARRAY_TRAITS_H
#define PPS_MULTI_ARRAY_TRAITS_H

#include "multi_array_traits_iterator.h"
#include "multi_array_traits_baseType.h"
#include "multi_array_traits_depth.h"

namespace pps {
namespace multi_array {

template<class T>
struct traits
{
	typedef typename traits_iterator<T>::type iterator;
	typedef typename traits_baseType<T>::type baseType;
	static const std::size_t depth = traits_depth<T>::value;

	typename iterator begin(const T& p_multiArray, const range<std::size_t>& p_view)
	{
		return &p_multiArray + *(p_view.begin());
	}
};

}}

#endif
