#include "18_8_QueryResult.h"
#include "18_8_TextQuery.h"
#include "18_8_AndQuery.h"
#include <algorithm>
#include <iterator>
#include <set>
#include <memory>

QueryResult AndQuery::eval(const TextQuery &tq, line_no range_start, line_no range_end) const {
	#ifdef VERBOSE
		std::cout << "AndQuery eval" << std::endl;
	#endif
	auto lhs_result = lhs.eval(tq, range_start, range_end);
	auto rhs_result = rhs.eval(tq, range_start, range_end);
	auto lines = std::make_shared<std::set<line_no>>();
	std::set_intersection(lhs_result.begin(), lhs_result.end(), rhs_result.begin(), rhs_result.end(), std::inserter(*lines, lines->begin()));
	return QueryResult(rep(), *lhs_result.get_file(), lines);
}