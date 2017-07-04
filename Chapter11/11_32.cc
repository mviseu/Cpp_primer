#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>

using std::multimap;
using std::set;
using std::string;
using std::cout;
using std::endl;
using std::cout;
using std::endl;
using std::copy;
using std::for_each;
using std::pair;

int main() {
  multimap<string, string> bookstore = {{"Jane Austen", "Pride and Prejudice"},
                                        {"Shakespeare", "Romeo and Juliet"},
                                        {"Shakespeare", "Hamlet"}};
  std::ostream_iterator<string> out(cout, " ");
  // multimap keys are already in alphabetical order
  auto iter_author = bookstore.cbegin();
  while (iter_author != bookstore.cend()) {
    out = iter_author->first;
    auto range_books = bookstore.equal_range(iter_author->first);
    set<string> books;

    for_each(range_books.first, range_books.second,
             [&books](multimap<string, string>::value_type book) {
               books.insert(book.second);
             });
    copy(books.cbegin(), books.cend(), out);
    cout << endl;
    iter_author = range_books.second;
  }
  return 0;
}