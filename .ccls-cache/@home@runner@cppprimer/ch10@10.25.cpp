#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
using namespace std::placeholders;

void elimDups(vector<string> &words) {
  sort(words.begin(), words.end());
  auto unique_end = unique(words.begin(), words.end());
  words.erase(unique_end, words.end());
}

string make_plural(vector<string>::iterator::difference_type count, string s,
                   string plur_chars) {
  return (count == 1) ? s : s + plur_chars;
}

bool is_bigger(const string &s, string::size_type sz) { return s.size() >= sz; }

void biggies(vector<string> &words, vector<string>::size_type sz) {
  elimDups(words); // Remove duplicates and sort by alphabetical order
  const auto wf =
      partition(words.begin(), words.end(), bind(is_bigger, _1, sz));
  auto count = wf - words.begin();
  cout << count << " " << make_plural(count, "word", "s") << " of length " << sz
       << " or longer" << endl;

  for_each(words.begin(), wf, [](const string &s) { cout << s << " "; });
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

  biggies(words, 5);
}