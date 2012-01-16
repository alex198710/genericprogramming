#ifndef PPS_MULTI_ARRAY_TRAITS_H
#define PPS_MULTI_ARRAY_TRAITS_H

#include "multi_array_traits_baseType.h"
#include "multi_array_traits_iterator.h"

namespace pps {
namespace multi_array {

template<class T>
struct traits
{
	typedef typename traits_baseType<T>::baseType baseType;				// A better solution please...
	typedef typename traits_iterator<T>::constIterator constIterator;	// Idem...
	typedef typename traits_iterator<T>::iterator iterator;				// Idem...
//	static const std::size_t depth = traits_depth<T>::depth;			// Useless

	/*
	--------------------------------------------------------------------
		If an assertion occurs here, it means that you're trying to
		use the multiArray::traits without having specified it for
		your particular user-made type.

		Extension example:
		----
			// A user-made class that behave like
			// an array of integers.
			class MyClass
			{
				public:
					typedef int myValueType;
					typedef const int* myConstIterator;
					typedef int* myIterator;
			};

			template<class T>
			struct traits_baseType<MyClass>
			{
				typedef MyClass::myValueType baseType;
			};

			template<class T>
			struct traits_iterator<MyClass>
			{
				typedef MyClass::myConstIterator constIterator;
				typedef MyClass::myIterator iterator;
			};
		----
	--------------------------------------------------------------------
	*/
	static_assert(!std::is_same<T, baseType>::value, "[traits]: Missing specialization for traits_baseType");
	static_assert(!std::is_same<T, constIterator>::value, "[traits]: Missing specialization for traits_iterator");
	static_assert(!std::is_same<T, iterator>::value, "[traits]: Missing specialization for traits_iterator");
};

/*
	typename iterator begin(const T& p_multiArray, const range<std::size_t>& p_view)
	{
		return &p_multiArray + *(p_view.begin());
	}
*/

}}

#endif
