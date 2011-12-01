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
struct multi_array
{
	typename T type;
};

template<>
struct multi_array
{

};

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
			m_indexes.push_back(p_index)
			return *this;
		}

		int getIndexesCount()
		{
			return m_indexes.size();
		}

		int getIndex(int p_index)
		{
			return m_indexes[p_index];
		}
};

template<class T, class U>
multi_array::type
fill(const T& p_array, const multi_array_indexes& p_indexes, const U& p_fill)
{
}

int main(int p_argc, char* p_argv[])
{
	int matrixWidth = 20;
	int matrixHeight = 10;
	int** matrix = new int*[matrixWidth];

	for(int i = 0 ; i < matrixWidth ; ++i)
		matrix[i] = new int[matrixHeight];

	fill(matrix, multi_array_indexes[20][10], 0);
	get(matrix, multi_array_indexes[20][10], multi_array_indexes[0][0]);

	for(int i = 0 ; i < 10 ; ++i)
		delete[] matrix[i];
	delete[] matrix;

	return 0;
}
