#ifndef PPS_MULTI_ARRAY_STACK_H
#define PPS_MULTI_ARRAY_STACK_H

#include <list>

namespace pps {
namespace multi_array {

template<class T>
class stack
{
	private:
		std::list<T> m_data;

	public:
		stack();
		stack(const stack<T>& p_stack);

		stack<T>& operator=(const stack<T>& p_stack);
		stack<T>& operator[](const T& p_value);

		inline std::size_t size() const;

		inline const T& first() const;
		stack<T> child() const;
};

}}

namespace pps {
namespace multi_array {

template<class T>
stack<T>::stack()
{
}

template<class T>
stack<T>::stack(const stack<T>& p_stack)
: m_data(p_stack.m_data)
{
}

template<class T>
stack<T>& stack<T>::operator=(const stack<T>& p_stack)
{
	if(&p_stack == this)
		return *this;

	m_data = p_stack.m_data;

	return *this;
}

template<class T>
stack<T>& stack<T>::operator[](const T& p_value)
{
	m_data.push_back(p_value);

	return *this;
}

template<class T>
inline std::size_t stack<T>::size() const
{
	return m_data.size();
}

template<class T>
inline const T& stack<T>::first() const
{
	return m_data.front();
}

template<class T>
stack<T> stack<T>::child() const
{
	stack<T> child(*this);
	child.m_data.pop_front();
	return child;
}

}}

#endif
