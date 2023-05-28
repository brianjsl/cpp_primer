#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool more_five(const string &s) { return s.size() > 5; }

int main() {
  vector<string> words = {"hello", "whatever", "brianlee",
                          "foo",   "bar",      "foobar"};
  const auto part_end = partition(words.begin(), words.end(), more_five);
  words.erase(part_end, words.cend());

  for (const auto &w : words) {
    cout << w << " ";
  }
  cout << endl;
  return 0;
}