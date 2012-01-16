// http://stackoverflow.com/questions/6173226/virtual-forward-iterator

#include <iostream>
#include <typeinfo>
#include <vector>
#include "multi_array.h"

/*
template<class T, int N>
class MultiArray
{
	private:
		MultiArray<T, N-1> m_impl*;
};

template<class T>
class MultiArray<1>
{

};
*/

template<class T>
class multi_array_indexes
{
	private:
		std::vector<int> m_indexes;

	public:
		multi_array_indexes()
		{
		}

		multi_array_indexes& operator[](int p_index)
		{
			m_indexes.push_back(p_index);
			return *this;
		}

		int size()
		{
			return m_indexes.size();
		}

		int operator[](int p_index)
		{
			return m_indexes[p_index];
		}
};

/*
template<class T, class U>
void fill(const T& p_array, const multi_array_indexes& p_indexes, const multi_array<T>::type& p_value)
{
}

fill<int[2][19]>(vector, 0);
fill(vector, 0);
*/




fill(myMultiArray, multi_array_ranges[multi_array_range(1, 3)][multi_array_range(10)], 0);
get(myMultiArray, multi_array_ranges[multi_array_range(1, 3)][multi_array_range(10)], multi_array_indexes[0][0]);

template<int N>
class multi_array_ranges_impl
{
	private:
		
};

template<int N>
class multi_array_ranges
{
	multi_array_ranges<N+1> operator[](std::size_t p_begin, std::size_t p_end);
};

fill(myMultiArray, 0);
// disable T*
// auto detect size
// force encapsulation of T* (static_assert)

int main(int p_argc, char* p_argv[])
{
	int matrixWidth = 20;
	int matrixHeight = 10;
	int** matrix = new int*[matrixWidth];

	for(int i = 0 ; i < matrixWidth ; ++i)
		matrix[i] = new int[matrixHeight];

/*
	fill(matrix, multi_array_indexes[20][10], 0);
	get(matrix, multi_array_indexes[20][10], multi_array_indexes[0][0]);
*/

int test[][2] = {
	{2,1},
	{3,4},
	{6,4}
};
std::cout << sizeof(test) / sizeof(int) << std::endl;

	for(int i = 0 ; i < 10 ; ++i)
		delete[] matrix[i];
	delete[] matrix;

	return 0;
}





/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////




template<class T>
struct multi_array_traits_baseType
{
	typedef T type;
};

template<class T>
struct multi_array_traits_baseType<T*>
{
	typedef multi_array_traits_baseType<T> type;
};

template<class T, class U>
struct multi_array_traits_baseType<U<T>>
{
	typedef multi_array_traits_baseType<T> type;
};

template<class T, std::size_t N>
struct multi_array_traits_depth
{
	static const std::size_t value = N;
};

template<std::size_t N>
struct multi_array_traits_depth<T*>
{
	static const std::size_t value = multi_array_traits_depth<T>::value;
};

template<class T>
struct multi_array_traits
{
	typedef multi_array_traits_baseType<T>::type baseType;
	static const std::size_t depth = multi_array_traits_depth<T>::value;
	typedef T::iterator iterator;
};

class multi_array_indexes
{
	private:
		std::vector<std::size_t> m_indexes;

	public:
		multi_array_indexes& operator[](std::size_t p_index)
		{
			m_indexes.push_back(p_index);
			return *this;
		}
};

template<class T>
std::iterator
begin(const T& p_multiArray, const multi_array_indexes& p_dimensions)
{
	return multi_array_traits<T>::iterator(p_multiArray);
}

template<class T>
std::iterator
end(const T& p_multiArray, const multi_array_indexes& p_dimensions)
{
	return multi_array_traits<T>::iterator(p_multiArray + p_dimensions.last());
}

template<class T>
multi_array_traits<T>::base_type
get(const T& p_multiArray, const multi_array_indexes& p_dimensions, const multi_array_indexes& p_indexes)
{
	std::iterator it(begin(p_multiArray, p_dimensions));

	if(p_dimensions.size() == 1)
		return *(it + );
}

void todo()
{
	// En tout premier lieu, on va gérer des index en dur.
	// Peut importe ce que la fonction recoit en entrée, elle peut le gérer.
	// L'écriture est cependant un peu lourde.
	// Une grande partie des tests sont effectués au runtime.
	std::vector<std::list<int[5]>*> test1;
	get(test1, multi_array_indexes[3][2][4][5], multi_array_indexes[0][0][0][0]);

	// Par la suite, mise en place des vues pour rendre l'écriture plus viable.
	// On ajoute une fonctionnalité intéressante sans grand changement.
	std::list<int**> test2;
	get(test2, multi_array_indexes[multi_array_range(2, 5)][4][multi_array_range(1, 2)], multi_array_indexes[0][0][0]);

	// On peut ensuite ajouter un mécanisme de vérification de profondeur des éléments passés
	// aux fonctions au compile time.
	// On rendrait ainsi invalide un des exemples suivants.
	int*** testError1;
	get(testError1, multi_array_indexes[1][2], multi_array_indexes[0][0][0]);
	get(testError1, multi_array_indexes[1][2][3], multi_array_indexes[0][0]);
	get(testError1, multi_array_indexes[1][2], multi_array_indexes[0][0]);

	// Pour alléger l'écriture, on pourrait requêter sur la taille des collections dynamiques.
	// Dans le cas de collections statiques (int[5]), on pourrait aussi s'arranger.
	// Mais il faut exclure les T* car on ne peut pas connaître leur taille !!!
	std::list<std::vector<double>> test3;
	get(test3, multi_array_indexes[0][0]);

	// Enfin, pour tester l'extensibilité, il faudrait développer un tout bête multi_array.
	// Penser au is_pod<> pour éviter les constructions d'éléments simples.
	multi_array<int, 4> test4(multi_array_indexes[3][2][2][6]);
	get(test4, multi_array_indexes[0][0][0][0]);
}

template<class T>
traits<T>::base_type
get(
	const T& p_multiArray,
	const range<std::size_t>& p_dimensions,
	const range<std::size_t>& p_indexes
)
{
	range<std::size_t>::iterator itDimensions(p_dimensions.begin());
	if(itDimensions == p_dimensions.end())
		return p_multiArray;

	range<std::size_t>::iterator itIndexes(p_indexes.begin());
	traits<T>::iterator itData(traits<T>::begin(p_multiArray, p_dimensions));
	for(std::size_t i = 0, end = *itIndexes ; i < end ; ++i)
		++itData;

	return get(
		*itData,
		range<std::size_t>(++itDimensions, p_dimensions.end()),
		range<std::size_t>(++itIndexes, p_indexes.end())
	);
}
/*
get(const T& p_multiArray, const dimensions& p_dimensions, const indexes& p_indexes)
{
	traits<T>::iterator itData(begin(p_multiArray, p_dimensions));
	for(std::size_t i = 0, end = p_indexes.first() ; i < end ; ++i)
		++itData;

	if(p_dimensions.size() == 1)
		return *itData;

	return get(*itData, p_dimensions.child(), p_indexes.child());
}
*/

template<class T>
traits<T>::base_type
get(
	const T& p_multiArray,
	const range<range<std::size_t>>& p_view,
	const range<std::size_t>& p_indexes
)
{
	range<range<std::size_t>>::iterator itView(p_view.begin());
	if(itView == p_view.end())
		return p_multiArray;

	range<std::size_t>::iterator itFirstView(*itView.begin());
	range<std::size_t>::iterator itIndexes(p_indexes.begin());
	for(std::size_t i = 0, end = *p_indexes.begin() ; i < end ; ++i)
		++itFirstView;

	traits<T>::iterator itData(traits<T>::begin(p_multiArray, p_view));
	for(std::size_t i = 0, end = *itFirstView ; i < end ; ++i)
		++itData;

	return get(
		*itData,
		range<range<std::size_t>>(++itView, p_view.end()),
		range<std::size_t>(++itIndexes, p_indexes.end())
	);
}
/*
get(const T& p_multiArray, const view& p_view, const indexes& p_indexes)
{
	view::iterator itView(p_view.first().begin());
	for(std::size_t i = 0, end = p_indexes.first() ; i < end ; ++i)
		++itView;

	traits<T>::iterator itData(begin(p_multiArray, p_view));
	for(std::size_t i = 0, end = *itView ; i < end ; ++i)
		++itData;

	if(p_view.size() == 1)
		return *itData;

	return get(*itData, p_view.child(), p_indexes.child());
}
*/

/*

---------------------------------------------------------
 La librairie contiendra des fonctions de manipulation
 des tableaux à N dimensions. Ci-dessous, des exemples
 de fonctions à implémenter.
---------------------------------------------------------

get		Retourne l'élément à l'index précisé.
		Une version const T& et une version T& seront
		disponibles pour pouvoir modifier dans la foulée
		un élément.
fill	Rempli un tableau avec une valeur.

---------------------------------------------------------
 On met en place plusieurs version des différentes
 fonctions pour pouvoir s'adapter à de nombreux cas
 d'utilisation.
---------------------------------------------------------

1/ La première version prend un tableau multi-dimensionnel
aléatoire en entrée. Une simple extension de la structure
de "traits" permettra l'utilisation de cette fonction par
un objet custom.
Il faudra néanmoins passer la taille du tableau pour toutes
ses dimensions.

Exemple:

get(std::vector<int*>, dimensions()[3][7], indexes()[0][0]);


2/ La seconde version est similaire, sauf que le second
paramètre représente une vue sur le tableau multi-dimensionnel.
Cette vue correspond à tout ou portion du tableau.

Exemple:

get(std::vector<int*>, view()[view_range(3)][view_range(7)], indexes()[0][0]);


3/ Les versions suivantes de la fonction permettront l'auto-
detection de la taille des dimensions. Une éventuelle détection
de la taille d'un tableau statique (type int[7]) pourrait être
entreprise. Les pointeurs seront bien sur déclarés en erreur par
un static_assert.

Exemples:

get(std::vector<int>, indexes()[0]);
get(std::vector<int[7]>, indexes()[0][0]);

---------------------------------------------------------

*/

#include <type_info>

/*
// https://gist.github.com/1069605
template<class T, void (T::*)() = &T::begin>
struct traits_method_begin
{
};
*/

template<class T>
class range
{
	public:
		virtual traits<T>::const_iterator begin() const =0;
		virtual traits<T>::iterator begin() =0;
		virtual traits<T>::const_iterator end() const =0;
		virtual traits<T>::iterator end() =0;
};

class dimensions
	: public range<std::list<std::size_t>>
{
	public:
		typedef range<std::list<std::size_t>>::const_iterator const_iterator;
		typedef range<std::list<std::size_t>>::iterator iterator;

	private:
		std::list<std::size_t> m_data;

	public:
		dimensions()
		{
		}

		dimensions(const dimensions& p_dimensions)
		: m_data(p_dimensions.m_data)
		{
		}

		dimensions& operator=(const dimensions& p_dimensions)
		{
			if(&p_dimensions == this)
				return *this;

			m_data = p_dimensions.m_data;

			return *this;
		}

		virtual const_iterator begin() const
		{
			return m_data.begin();
		}

		virtual iterator begin()
		{
			return m_data.begin();
		}

		virtual const_iterator end() const
		{
			return m_data.end();
		}

		virtual iterator end()
		{
			return m_data.end();
		}
}

template<class T>
struct traits
{
	static_assert(false, "Traits not specialized for your particular use");
};

template<class T>
struct traits<T*>
{

	typedef typename traits_baseType<T>::type baseType;
	typedef typename T* iterator;
//	typedef typename const T* const_iterator;

	template<class Range>
	iterator begin(const T& p_multiArray, const View& p_dimensions);
//	const_iterator begin(const T& p_multiArray) const;
	iterator end(const T& p_multiArray);
//	const_iterator end(const T& p_multiArray);
};

template<class T>
get(const T& p_multiArray, const range<std::size_t> p_indexes)
{
	template<class T>
	struct traits
	{
		typedef typename T::iterator iterator;
	}

	template<class T>
	struct traits<T*>
	{
		static_assert(POINTER_NOT_ALLOWED);
	}

	template<class T, class N>
	struct traits<T[N]>
	{
		static std::size_t size = N;
	}
}

template<class T>
get(const T& p_multiArray, const range<std::size_t> p_dimensions, const range<std::size_t> p_indexes)
{
}

template<class T>
get(const T& p_multiArray, const range<range<std::size_t>> p_view, const range<std::size_t> p_indexes)
{
}

template<class T>
get(const range<T>& p_multiArray, const range<std::size_t> p_indexes)
{
}

// -------------------------------------------------------------------

template<class T>
struct range
{
	typedef T valueType;
	typedef T constIterator;
	typedef T iterator;
};

template<class T>
struct range<std::vector<T>>
{
	typedef T valueType;
	typedef typename std::vector<T>::const_iterator constIterator;
	typedef typename std::vector<T>::iterator iterator;
};

template<class T>
struct traits_baseType
{
	typedef T baseType;
};

template<class T>
struct traits_baseType<range<T>>
{
	typedef typename traits_baseType<range<T>::valueType>::baseType baseType;
};

template<class T>
struct traits
{
	typedef typename traits_baseType<T>::baseType baseType;
	typedef typename range<T>::constIterator constIterator;
	typedef typename range<T>::iterator iterator;
};

//std::enable_if<...>

template<class Range>
void begin(const Range& p_range)
{
	static_assert(false, "[constIterator begin]: No suitable specialization found");
}

template<class Range>
void begin(const Range& p_range)
{
	static_assert(false, "[iterator begin]: No suitable specialization found");
}

template<class Range>
void end(const Range& p_range)
{
	static_assert(false, "[constIterator end]: No suitable specialization found");
}

template<class Range>
void end(const Range& p_range)
{
	static_assert(false, "[iterator end]: No suitable specialization found");
}

template<class MultiArray, class View, class Indexes>
traits<MultiArray>::baseType
get(const MultiArray& p_multiArray, const View& p_view, const Indexes& p_indexes)
{
}