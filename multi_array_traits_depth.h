#ifndef PPS_MULTI_ARRAY_TRAITS_DEPTH_H
#define PPS_MULTI_ARRAY_TRAITS_DEPTH_H

namespace pps {
namespace multi_array {

template<class T, std::size_t N = 0>
struct traits_depth
{
	static const std::size_t value = N;
};

template<class T, std::size_t N>
struct traits_depth<T*, N>
{
	static const std::size_t value = traits_depth<T, N + 1>::value;
};

}}

#endif
