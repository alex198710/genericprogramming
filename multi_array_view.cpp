#include "multi_array_view.h"
/*
namespace pps {
namespace multi_array {

view::view()
{
}

view::view(const view& p_view)
: m_data(p_view.m_data)
{
}

view& view::operator=(const view& p_view)
{
	if(this == &p_view)
		return *this;

	m_data = p_view.m_data;

	return *this;
}

bool view::operator==(const view& p_view)
{
	return m_data == p_view.m_data;
}

bool view::operator!=(const view& p_view)
{
	return m_data != p_view.m_data;
}

std::size_t view::size() const
{
	return m_data.size();
}

const range& view::at(std::size_t p_index) const
{
	return m_data[p_index];
}

const range& view::last() const
{
	return m_data.back();
}

std::vector<range>::const_iterator view::begin() const
{
	return m_data.begin();
}

std::vector<range>::const_iterator view::end() const
{
	return m_data.end();
}

view& view::operator[](const range& p_range)
{
	m_data.push_back(p_range);
	return *this;
}

view view::parent() const
{
	view parent(*this);
	parent.m_data.pop_back();
	return parent;
}

}}
*/