#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

bool contains_asc_desc(const string &s) {
  string asc_desc = "bdfghijklpqty"; // Ascenders and Descenders
  return (s.find_first_of(asc_desc) != string::npos);
}

string longest_word_wo_ascdesc(vector<string> &vec) {
  string::size_type longest_len = 0;
  string longest_word;
  for (const auto &s : vec) {
    if (!contains_asc_desc(s)) {
      if (s.length() > longest_len) {
        longest_len = s.length();
        longest_word = s;
      }
    }
  }

  return longest_word;
}

int main(int argc, char *argv[]) {
  ifstream input(argv[1]);
  vector<string> vec;
  string s;

  while (input >> s) {
    vec.push_back(s);
  }

  string longest_word = longest_word_wo_ascdesc(vec);
  cout << longest_word << endl;

  return 0;
}