#include "19_20_Query.h"
#include "19_20_OrQuery.h"
#include "19_20_TextQuery.h"
#include <memory>
#include <set>
#include <algorithm>
#include <iterator>

TextQuery::QueryResult OrQuery::eval(const TextQuery &tq, line_no range_start, line_no range_end) const {
	#ifdef VERBOSE
		std::cout << "OrQuery eval" << std::endl;
	#endif
	auto lhs_result = lhs.eval(tq, range_start, range_end);
	auto rhs_result = rhs.eval(tq, range_start, range_end);	
	auto lines = std::make_shared<set<line_no>>(lhs_result.begin(), lhs_result.end());
	lines->insert(rhs_result.begin(), rhs_result.end());
	return TextQuery::QueryResult(rep(), *lhs_result.get_file(), lines);
}


