#include "NotQuery.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include <set>
#include <memory>

QueryResult NotQuery::eval(const TextQuery &tq, line_no range_start, line_no range_end) const {
	#ifdef VERBOSE
		std::cout << "NotQuery eval" << std::endl;
	#endif
	auto yes_result = qr.eval(tq, range_start, range_end);
	auto yes_line_n = yes_result.begin(), yes_line_end = yes_result.end();

	auto not_lines = std::make_shared<std::set<line_no>>();
	for(line_no n = range_start - 1; n <= range_end - 1; ++n) {
		if(yes_line_n == yes_line_end || *yes_line_n != n) {
			not_lines->insert(n);
		} else {
			++yes_line_n;
		}
	}
	return QueryResult(rep(), *yes_result.get_file(), not_lines);
}	