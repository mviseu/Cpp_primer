#include "NotQuery.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include <set>
#include <memory>

QueryResult NotQuery::eval(const TextQuery &tq) const {
	std::cout << "NotQuery eval" << std::endl;
	auto yes_result = qr.eval(tq);
	auto yes_line_n = yes_result.begin(), yes_line_end = yes_result.end();

	auto not_lines = std::make_shared<std::set<line_no>>();
	line_no total_nr_lines = yes_result.get_file()->size();
	for(line_no n = 0; n != total_nr_lines; ++n) {
		if(yes_line_n == yes_line_end || *yes_line_n != n) {
			not_lines->insert(n);
		} else {
			++yes_line_n;
		}
	}
	return QueryResult(rep(), *yes_result.get_file(), not_lines);
}	