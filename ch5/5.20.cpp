#include <iostream>
#include <string>
using namespace std;

int main() {
  string s, currS;
  cout << "Enter a string: ";
  while (cin >> s) {
    if (s == currS) {
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