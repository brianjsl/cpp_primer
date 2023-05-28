#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void elimDups(vector<string> &words) {
  sort(words.begin(), words.end());
  auto unique_end = unique(words.begin(), words.end());
  words.erase(unique_end, words.end());
}

string make_plural(vector<string>::iterator::difference_type count, string s,
                   string plur_chars) {
  return (count == 1) ? s : s + plur_chars;
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
  elimDups(words); // Remove duplicates and sort by alphabetical order
  auto count = count_if(words.begin(), words.end(),
                        [sz](const string &word) { return word.size() >= sz; });
  cout << count << " " << make_plural(count, "word", "s") << " of length " << sz
       << " or longer" << endl;

  cout << endl;
}

int main() {
  string s = "the quick red fox jumps over the slow red turtle";
  istringstream is(s);
  vector<string> words;

  string tmp;
  while (is >> tmp) {
    words.push_back(tmp);
  }

  biggies(words, 6);
}