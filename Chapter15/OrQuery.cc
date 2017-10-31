#include "Query.h"
#include "OrQuery.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include <memory>
#include <set>
#include <algorithm>
#include <iterator>

QueryResult OrQuery::eval(const TextQuery &tq) const {
	auto lhs_result = lhs.eval(tq);
	auto rhs_result = rhs.eval(tq);	
	auto lines = std::make_shared<set<line_no>>(lhs_result.begin(), lhs_result.end());
	lines->insert(rhs_result.begin(), rhs_result.end());
	return QueryResult(rep(), *lhs_result.get_file(), lines);
}

