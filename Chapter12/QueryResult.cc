#include "QueryResult.h"
#include <memory>
#include <string>
#include <set>

using std::shared_ptr;
using std::string;
using std::set;
using std::map;

class TextQuery;

QueryResult::QueryResult(shared_ptr<TextQuery> sptr, string wd) : tq_ptr(sptr), word(wd) {
	//what is the word count
}

/*class QueryResult {
	QueryResult(shared_ptr<TextQuery> sptr, string word);
	
private:
	shared_ptr<TextQuery> tq_ptr;
	string word;
	int word_count;
	map<set<int>, string> &line_nr_text;

};*()