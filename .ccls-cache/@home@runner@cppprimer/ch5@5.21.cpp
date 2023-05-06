#include <iostream>
#include <string>
using namespace std;

int main() {
  string s, currS;
  cout << "Enter a string: ";
  while (cin >> s) {
    if (islower(s[0]))
      continue;
    if (s == currS and !s.empty()) {
      cout << s << " was repeated" << endl;
      break;
    } else {
      currS = s;
    }
  }
  if (!cin) {
    cout << "No word was repeated twice" << endl;
  }
  return 0;
}