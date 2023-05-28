#include "Sales_item.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  ifstream f(argv[1]);
  istream_iterator<Sales_item> is(f), eof;
  vector<Sales_item> trans;
  copy(is, eof, back_inserter(trans));
  sort(trans.begin(), trans.end(), compareIsbn);

  Sales_item total;
  auto it = trans.begin();
  while (it != trans.end()) {
    string curr_isbn = it->isbn();
    auto last_isbn = find_if(it, trans.end(), [curr_isbn](Sales_item &item) {
      return item.isbn() != curr_isbn;
    });
    total = accumulate(it, last_isbn, Sales_item(it->isbn()));
    cout << total << endl;
    it = last_isbn;
  }
  return 0;
}