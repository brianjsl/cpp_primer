
#include <iostream>
using namespace std;

int main() {
  int vowels = 0, blanks = 0, tabs = 0, newlines = 0;
  string s;
  while (cin >> s) {
    for (char c : s) {
      c = tolower(c);
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        ++vowels;
      } else if (c == ' ') {
        ++blanks;
      } else if (c == '\t') {
        ++tabs;
      } else if (c == '\n') {
        ++newlines;
      }
    }
  }
  cout << vowels << endl;
  cout << blanks << endl;
  cout << tabs << endl;
  cout << newlines << endl;
  return 0;
}