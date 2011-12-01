template<class T>
struct multi_array
{
	typedef T base_type;
};

template<class T>
struct multi_array<T*>
{
	typedef typename multi_array<T>::base_type base_type;
};
