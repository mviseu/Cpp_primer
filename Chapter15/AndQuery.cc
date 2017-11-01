#include "QueryResult.h"
#include "TextQuery.h"
#include "AndQuery.h"
#include <algorithm>
#include <iterator>
#include <set>
#include <memory>

QueryResult AndQuery::eval(const TextQuery &tq) const {
	auto lhs_result = lhs.eval(tq);
	auto rhs_result = rhs.eval(tq);
	auto lines = std::make_shared<std::set<line_no>>();
	std::set_intersection(lhs_result.begin(), lhs_result.end(), rhs_result.begin(), rhs_result.end(), std::inserter(*lines, lines->begin()));
	return QueryResult(rep(), *lhs_result.get_file(), lines);
}