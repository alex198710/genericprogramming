#ifndef PPS_MULTI_ARRAY_TRAITS_ITERATOR_H
#define PPS_MULTI_ARRAY_TRAITS_ITERATOR_H

namespace pps {
namespace multi_array {

template<class T>
struct traits_iterator
{
	typedef T* type;
};

template<class T>
struct traits_iterator<T*>
{
	typedef typename traits_iterator<T>::type* type;
};

}}

#endif
