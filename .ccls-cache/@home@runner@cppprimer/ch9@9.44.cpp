#include <iostream>
#include <string>
using namespace std;

int main() {
  string s = "hello what in the wrld is going on with this wrld";
  string oldVal = "wrld";
  string newVal = "world";

  for (string::size_type i = 0; i <= s.length(); ++i) {
    if (s.substr(i, oldVal.length()) == oldVal) {
      s.replace(i, oldVal.length(), newVal);
    }
  }

  cout << s << endl;
  return 0;
}