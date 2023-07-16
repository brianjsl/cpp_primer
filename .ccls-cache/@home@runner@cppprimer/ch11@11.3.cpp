#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
using namespace std;

int main() {
  string s = "blah thing text thing blah as an blah as a an except what blah";
  map<string, string::size_type> words;
  set<string> excluded_words = {"as", "an", "a"};
  istringstream is(s);
  string word;
  while (is >> word) {
    if (excluded_words.find(word) == excluded_words.end())
      ++words[word];
  }
  for (const auto &w : words) {
    cout << w.first << " occurs " << w.second
         << ((w.second > 1) ? " times" : " time") << endl;
  }
  return 0;
}