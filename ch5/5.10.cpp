#include <iostream>
using namespace std;

int main() {
  int vowels = 0;
  string s;
  while (cin >> s) {
    for (char c : s) {
      c = tolower(c);
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        ++vowels;
      }
    }
  }
  cout << vowels << endl;
  return 0;
}