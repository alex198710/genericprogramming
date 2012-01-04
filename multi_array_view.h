#ifndef PPS_MULTI_ARRAY_VIEW_H
#define PPS_MULTI_ARRAY_VIEW_H
/*
#include <vector>
#include <cstdio>
#include "multi_array_range.h"

namespace pps {
namespace multi_array {

class view
{
	private:
		std::vector<range> m_data;

	public:
		view();
		view(const view& p_view);

		view& operator=(const view& p_view);

		bool operator==(const view& p_view);
		bool operator!=(const view& p_view);

		std::size_t size() const;
		const range& at(std::size_t p_index) const;
		const range& last() const;

		std::vector<range>::const_iterator begin() const;
		std::vector<range>::const_iterator end() const;

		view& operator[](const range& p_range);

		view parent() const;
};

}}
*/
#endif
