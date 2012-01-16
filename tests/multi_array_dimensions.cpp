#include "../multi_array_dimensions.h"
#include "tests.h"

using pps::multi_array::dimensions;

template<class T>
struct range
{
	typedef T valueType;
	typedef const T& constReference;
	typedef T& reference;
	typedef const T* constIterator;
	typedef T* iterator;

//	static_assert(!std::is_same<T, T>::value, "[pps::range::range]: Missing specialization for [range] structure");
};
/*
template<class T>
struct range<T*>
{
	typedef T valueType;
	typedef const T& constReference;
	typedef T& reference;
	typedef const T* constIterator;
	typedef T* iterator;
};

template<class T, int N>
struct range<T[N]>
{
	typedef T valueType;
	typedef const T& constReference;
	typedef T& reference;
	typedef const T* constIterator;
	typedef T* iterator;
};

template<class T>
struct range<std::vector<T>>
{
	typedef T valueType;
	typedef typename std::vector<T>::const_reference constReference;
	typedef typename std::vector<T>::reference reference;
	typedef typename std::vector<T>::const_iterator constIterator;
	typedef typename std::vector<T>::iterator iterator;
};
*/
/*
template<class T>
struct traits_baseType
{
	typedef T baseType;
};

template<class T>
struct traits_baseType<range<T>>
{
	typedef typename range<T>::valueType valueType;
	typedef traits_baseType<valueType> childType;
	typedef typename childType::baseType baseType;
};

template<class T>
struct traits
{
	typedef typename range<T>::valueType valueType;
	typedef typename range<T>::constReference constReference;
	typedef typename range<T>::reference reference;
	typedef typename range<T>::constIterator constIterator;
	typedef typename range<T>::iterator iterator;
	typedef typename traits_baseType<T>::childType childType;
	typedef typename childType::baseType baseType;

	/
		Big explanation here!
	/
	static_assert(!std::is_same<T, baseType>::value, "[range::traits]: Missing specialization");
};

//std::enable_if<...>

template<class T>
inline
typename std::vector<T>::const_iterator
begin(const std::vector<T>& p_range)
{
	return p_range.begin();
}

template<class T>
inline
typename std::vector<T>::iterator
begin(const std::vector<T>& p_range)
{
	return p_range.begin();
}

template<class T>
inline
typename std::vector<T>::const_iterator
end(const std::vector<T>& p_range)
{
	return p_range.end();
}

template<class T>
inline
typename std::vector<T>::iterator
end(const std::vector<T>& p_range)
{
	return p_range.end();
}

template<class MultiArray, class Indexes>
get(const MultiArray& p_multiArray, const Indexes& p_indexes)
{
	typename range<Indexes>::constIterator itIndexes(begin(p_indexes));
	typename range<MultiArray>::constIterator itData(begin(p_multiArray));
	for(std::size_t i = 0, end = *itIndexes ; i < end ; ++i)
		++itData;

	return *itData;
}

template<class MultiArray, class View, class Indexes>
get(const MultiArray& p_multiArray, const View& p_view, const Indexes& p_indexes)
{
	typename range<View>::constIterator itView(begin(p_view));
	typedef typename range<View>::valueType SubView;
	typename range<SubView>::constIterator itSubView(begin(*itView));
	typename range<Indexes>::constIterator itIndexes(begin(p_indexes));
	for(std::size_t i = 0, end = *itIndexes ; i < end ; ++i)
		++itSubView;

	typename range<MultiArray>::constIterator itData(begin(p_multiArray));
	for(std::size_t i = 0, end = *itSubView ; i < end ; ++i)
		++itData;

	return *itData;
}
*/
/*
template<class T>
typename range<T>::constIterator
begin(const T& p_range)
{
	static_assert(!std::is_same<T, T>::value, "[pps::range::begin]: Missing specialization for [constIterator range::begin] function");
}

template<class T>
typename range<T>::iterator
begin(T& p_range)
{
	static_assert(!std::is_same<T, T>::value, "[pps::range::begin]: Missing specialization for [iterator range::begin] function");
}

template<class T>
typename range<T*>::constIterator
begin(const T* p_range)
{
	return p_range;
}

template<class T>
typename range<T*>::iterator
begin(T* p_range)
{
	return p_range;
}

template<class T>
inline
typename std::vector<T>::const_iterator
begin(const std::vector<T>& p_range)
{
	return p_range.begin();
}

template<class T>
inline
typename std::vector<T>::iterator
begin(std::vector<T>& p_range)
{
	return p_range.begin();
}
*/

template<class T>
struct test : range<T>
{
};

int main()
{
	test<int>::valueType i;

/*
	int t1[] = {1, 2, 3};
	range<int*>::iterator it1(begin(t1));

	std::vector<int> t2;
	t2.push_back(1);
	t2.push_back(2);
	t2.push_back(3);

	range<std::vector<int>>::iterator it2(begin(t2));
*/
/*
	std::vector<std::size_t> r1;
	r1.push_back(4);
	r1.push_back(9);
	r1.push_back(7);

	typedef typename range<std::vector<std::size_t>>::constIterator constIterator;
	typedef typename range<std::vector<std::size_t>>::iterator iterator;

	constIterator it1(begin(r1));
	iterator it2(begin(r1));

	constIterator it3(end(r1));
	iterator it4(end(r1));

	PPS_TESTS_ASSERT(it1 == r1.begin());
	PPS_TESTS_ASSERT(it2 == r1.begin());
	PPS_TESTS_ASSERT(it3 == r1.end());
	PPS_TESTS_ASSERT(it4 == r1.end());

	std::vector<std::vector<std::size_t>> r2;
	std::vector<std::size_t> r3;
	r3.push_back(0);
	r3.push_back(1);
	r3.push_back(2);
	r2.push_back(r3);

	std::vector<std::size_t> r4;
	r4.push_back(0);

	PPS_TESTS_ASSERT(get(r1, r2, r3) == 4);
	PPS_TESTS_ASSERT(get(r1, r3) == 4);
*/
/*
	dimensions d1;
	PPS_TESTS_ASSERT(d1.begin() == d1.end());

	d1[3][4];
	dimensions::iterator itD1(d1.begin());
	PPS_TESTS_ASSERT(*itD1++ == 3);
	PPS_TESTS_ASSERT(*itD1++ == 4);
	PPS_TESTS_ASSERT(itD1 == d1.end());

	dimensions d2(d1);
	dimensions::iterator itD2(d2.begin());
	PPS_TESTS_ASSERT(*itD2++ == 3);
	PPS_TESTS_ASSERT(*itD2++ == 4);
	PPS_TESTS_ASSERT(itD2 == d2.end());

	dimensions d3 = d1;
	dimensions::iterator itD3(d3.begin());
	PPS_TESTS_ASSERT(*itD3++ == 3);
	PPS_TESTS_ASSERT(*itD3++ == 4);
	PPS_TESTS_ASSERT(itD3 == d3.end());

	dimensions d4 = dimensions()[1][2];
	dimensions::iterator itD4(d4.begin());
	PPS_TESTS_ASSERT(*itD4++ == 1);
	PPS_TESTS_ASSERT(*itD4++ == 2);
	PPS_TESTS_ASSERT(itD4 == d4.end());
*/
	return 0;
}
