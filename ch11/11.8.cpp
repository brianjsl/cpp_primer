#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  // Vector will have slow search (on average) at O(n) where n is the
  // place in the array while set has O(logN) where N is the size of the
  // container
  string s = "blah thing text thing Blah as an blah as a an except what blah";
  map<string, string::size_type> words;
  vector<string> excluded_words = {"as", "an", "a"};
  istringstream is(s);
  string word;
  while (is >> word) {
    word[0] = tolower(word[0]);
    if (find(excluded_words.begin(), excluded_words.end(), word) ==
        excluded_words.end()) {
      ++words[word];
    }
  }
  for (const auto &w : words) {
    cout << w.first << " occurs " << w.second
         << ((w.second > 1) ? " times" : " time") << endl;
  }
  return 0;
}