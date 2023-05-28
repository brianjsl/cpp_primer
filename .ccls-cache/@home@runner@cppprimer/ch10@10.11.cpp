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

bool isShorter(const string &word1, const string &word2) {
  return word1.size() < word2.size();
}

void print(vector<string> &words) {
  for (const auto &w : words) {
    cout << w << " ";
  }
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

  elimDups(words);
  stable_sort(words.begin(), words.end(), isShorter);
  print(words);
}