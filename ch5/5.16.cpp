#include <iostream>
using namespace std;

int main() {
  string s;
  while (cin >> s) {
    /* */
  }

  for (; cin >> s;) {
    /* */
  }

  for (auto c = s.begin(); c != s.end(); ++c) {
    /* */
  }

  auto c = s.begin();
  while (c != s.end()) {
    /* */
    ++c;
  }

  // For loop is a bit cleaner
}