#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
Easier to use the subscript program since it is
less verbose and no need to store intermediate types
like the return value pair
*/
int main() {
  map<string, size_t> word_count;
  string word;
  while (cin >> word) {
    auto ret = word_count.insert({word, 1});
    if (!ret.second) {
      ++ret.first->second;
    }
  }
  return 0;
}