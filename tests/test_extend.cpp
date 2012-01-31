#include <string>
#include <list>
#include "tests.h"
#include "../include/pps/range/traits.h"
#include "../include/pps/range/begin.h"
#include "../include/pps/range/end.h"

class MyFakeContainer
{
	public:
		typedef typename std::list<std::string>::iterator iterator;
		typedef typename std::list<std::string>::const_iterator constIterator;

	private:
		std::list<std::string> m_list;

	public:
		MyFakeContainer()
		: m_list()
		{
		}

		MyFakeContainer(const MyFakeContainer& p_container)
		: m_list(p_container.m_list)
		{
		}

		MyFakeContainer& operator=(const MyFakeContainer& p_container)
		{
			if(&p_container == this)
				return *this;

			m_list = p_container.m_list;

			return *this;
		}

		constIterator begin() const
		{
			return m_list.begin();
		}

		iterator begin()
		{
			return m_list.begin();
		}

		constIterator end() const
		{
			return m_list.end();
		}

		iterator end()
		{
			return m_list.end();
		}

		void pushBack(const std::string& p_string)
		{
			m_list.push_back(p_string);
		}
};

// Extending library to allow support of MyFakeContainer.
namespace pps {
namespace range {

/*
	Can be written in a more simple way since it is a simple
	composition of a std::list :
		template<>
		struct traits<MyFakeContainer>
			: traits<std::list<std::string>>
		{
		};
*/
template<>
struct traits<MyFakeContainer>
{
	typedef std::string valueType;
	typedef const std::string& constReference;
	typedef std::string& reference;
	typedef typename MyFakeContainer::constIterator constIterator;
	typedef typename MyFakeContainer::iterator iterator;
};

traits<MyFakeContainer>::constIterator
begin(const MyFakeContainer& p_range)
{
	return p_range.begin();
}

traits<MyFakeContainer>::iterator
begin(MyFakeContainer& p_range)
{
	return p_range.begin();
}

traits<MyFakeContainer>::constIterator
end(const MyFakeContainer& p_range)
{
	return p_range.end();
}

traits<MyFakeContainer>::iterator
end(MyFakeContainer& p_range)
{
	return p_range.end();
}

}}

using pps::range::traits;
using pps::range::begin;
using pps::range::end;

int main()
{
	MyFakeContainer c1;
	c1.pushBack("test");
	c1.pushBack("toto");
	c1.pushBack("youhou");

	auto it1(begin(c1));

	PPS_TESTS_ASSERT(*it1++ == "test");
	PPS_TESTS_ASSERT(*it1++ == "toto");
	PPS_TESTS_ASSERT(*it1++ == "youhou");
	PPS_TESTS_ASSERT(it1 == end(c1));

	// Testing nested containers.
	std::list<MyFakeContainer> c2;
	MyFakeContainer c21;
	c21.pushBack("truc");
	c21.pushBack("muche");
	MyFakeContainer c22;
	c22.pushBack("chose");
	c22.pushBack("bidule");
	c2.push_back(c21);
	c2.push_back(c22);

	auto it2(begin(c2));
	auto it3(begin(*it2));
	PPS_TESTS_ASSERT(*it3++ == "truc");
	PPS_TESTS_ASSERT(*it3++ == "muche");
	PPS_TESTS_ASSERT(it3 == end(*it2++));
	it3 = begin(*it2);
	PPS_TESTS_ASSERT(*it3++ == "chose");
	PPS_TESTS_ASSERT(*it3++ == "bidule");
	PPS_TESTS_ASSERT(it3 == end(*it2++));
	PPS_TESTS_ASSERT(it2 == end(c2));

	return 0;
}
