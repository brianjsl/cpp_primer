#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  string word;
  map<string, size_t> word_count;

  /*
  For each word that is read from cin, if the word is not in the
  word_count, adds it with value 0 and then increments it to 1.
  If the word is not in the word_count, then the value is merely
  incremented.
  */
  while (cin >> word) {
    ++word_count.insert({word, 0}).first->second;
  }
  for (const auto &c : word_count) {
    cout << c.first << ": " << c.second << endl;
  }
}