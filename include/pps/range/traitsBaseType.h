#ifndef PPS_TRAITS_BASE_TYPE_H#define PPS_TRAITS_BASE_TYPE_H#include "traits.h"namespace pps {namespace range {template<class T, int N>struct traitsBaseType{	typedef typename traits<T>::valueType valueType;	typedef traitsBaseType<valueType, N-1> childType;	typedef typename childType::baseType baseType;};template<class T>struct traitsBaseType<T, 0>{	typedef T baseType;};}}#endif