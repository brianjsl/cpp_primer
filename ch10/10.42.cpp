#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <string>
using namespace std;

void elimDups(list<string> &words) {
  words.sort();
  words.unique();
}

int main() {
  string s = "the quick red fox jumps over the slow red turtle";
  istringstream is(s);
  istream_iterator<string> is_iter(is), eos;
  list<string> words(is_iter, eos);
  elimDups(words);
  for (const auto &w : words) {
    cout << w << " ";
  }
  cout << endl;
  return 0;
}
