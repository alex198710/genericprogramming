#ifndef PPS_MULTI_ARRAY_TRAITS_BASE_TYPE_H
#define PPS_MULTI_ARRAY_TRAITS_BASE_TYPE_H

namespace pps {
namespace multi_array {

template<class T>
struct traits_baseType
{
	typedef T type;
};

template<class T>
struct traits_baseType<T*>
{
	typedef typename traits_baseType<T>::type type;
};

}}

#endif
