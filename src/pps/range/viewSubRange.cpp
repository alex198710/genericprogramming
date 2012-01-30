#include "../../../include/pps/range/viewSubRange.h"namespace pps {namespace range {viewSubRange::viewSubRange(std::size_t p_size, std::size_t p_increment): m_begin(0), m_end(p_size), m_increment(p_increment){}viewSubRange::viewSubRange(std::size_t p_begin, std::size_t p_end, std::size_t p_increment): m_begin(p_begin), m_end(p_end), m_increment(p_increment){}viewSubRange::viewSubRange(const viewSubRange& p_viewSubRange): m_begin(p_viewSubRange.m_begin), m_end(p_viewSubRange.m_end), m_increment(p_viewSubRange.m_increment){}viewSubRange& viewSubRange::operator=(const viewSubRange& p_viewSubRange){	if(&p_viewSubRange == this)		return *this;	m_begin = p_viewSubRange.m_begin;	m_end = p_viewSubRange.m_end;	m_increment = p_viewSubRange.m_increment;	return *this;}typename viewSubRange::iterator viewSubRange::begin() const{	return viewSubRangeIterator(m_begin, m_increment);}typename viewSubRange::iterator viewSubRange::end() const{	return viewSubRangeIterator(m_begin + (m_end / m_increment + 1) * m_increment, m_increment);}// ---- Extends library to support viewSubRange as a rangeviewSubRange::iteratorbegin(const viewSubRange& p_range){	return p_range.begin();}viewSubRange::iteratorbegin(viewSubRange& p_range){	return p_range.begin();}viewSubRange::iteratorend(const viewSubRange& p_range){	return p_range.end();}viewSubRange::iteratorend(viewSubRange& p_range){	return p_range.end();}}}