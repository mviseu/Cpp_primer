#include "19_6_Query.h"
#include "19_6_OrQuery.h"
#include "19_6_TextQuery.h"
#include "19_6_QueryResult.h"
#include <memory>
#include <set>
#include <algorithm>
#include <iterator>

QueryResult OrQuery::eval(const TextQuery &tq, line_no range_start, line_no range_end) const {
	#ifdef VERBOSE
		std::cout << "OrQuery eval" << std::endl;
	#endif
	auto lhs_result = lhs.eval(tq, range_start, range_end);
	auto rhs_result = rhs.eval(tq, range_start, range_end);	
	auto lines = std::make_shared<set<line_no>>(lhs_result.begin(), lhs_result.end());
	lines->insert(rhs_result.begin(), rhs_result.end());
	return QueryResult(rep(), *lhs_result.get_file(), lines);
}


