#include <iostream>
#include <string>
using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  // if (s1 == s2) {
  //   cout << "Strings are equal" << endl;
  // } else {
  //   if (s1 > s2) {
  //     cout << s1 << endl;
  //   } else {
  //     cout << s2 << endl;
  //   }
  // }
  if (s1.size() == s2.size()) {
    cout << "Strings have same length" << endl;
  } else {
    if (s1.size() > s2.size()) {
      cout << s1 << " is longer" << endl;
    } else {
      cout << s2 << " is longer" << endl;
    }
  }
  return 0;
}