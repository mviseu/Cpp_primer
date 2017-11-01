#include "Query.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include <fstream>
#include <iostream>

int main() {
	std::ifstream file("input_text.txt");

	TextQuery text(file);

	Query q = Query("fiery") & Query("bird") | Query("wind");
	//print(std::cout, q.eval(text));
	//q.eval(text);
	std::cout << q;
	return 0;
}

/*
1. Query(fiery, bird, wind) -> BaseQuery, WordQuery, Query(string)	(3x each)
2. & operator -> BaseQuery, BinaryQuery, AndQuery, constructor Query(shared_ptr) (1x each)
3. | operator -> BaseQuery, BinaryQuery, OrQuery, constructor Query(shared_ptr) (1x each)
Totals
Query string  3
Query shared - 2
BaseQuery - 5
WordQuery - 1
OrQuery - 1
AndQuery - 1
BinaryQuery - 2 
*/