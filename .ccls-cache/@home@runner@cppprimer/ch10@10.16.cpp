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
  stable_sort(words.begin(), words.end(),
              [](const string &w1, const string &w2) -> bool {
                return w1.size() < w2.size();
              }); // Sort by size
  const auto wf = find_if(words.begin(), words.end(), [sz](const string &word) {
    return word.size() >= sz;
  }); // Find the first word that has size larger than sz
  auto count = words.end() - wf;
  cout << count << " " << make_plural(count, "word", "s") << " of length " << sz
       << " or longer" << endl;

  for_each(wf, words.end(), [](const string &s) { cout << s << " "; });
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