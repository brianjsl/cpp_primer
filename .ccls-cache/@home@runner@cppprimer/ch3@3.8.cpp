#include <iostream>
#include <string>
using namespace std;

int main() {
  // Lesson: range for is shortest
  string s = "Blahblahblah";

  for (decltype(s.size()) i = 0; i < s.size(); i++) {
    s[i] = 'X';
  }

  // decltype(s.size()) i = 0;

  // while (i < s.size()) {
  //   s[i] = 'X';
  //   i++;
  // }

  cout << s << endl;
  return 0;
}