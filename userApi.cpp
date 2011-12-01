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
