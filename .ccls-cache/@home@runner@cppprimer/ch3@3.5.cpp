#include <iostream>
#include <string>
using namespace std;

int main() {
  string s = "", currString;
  while (cin >> currString) {
    s += currString + " ";
  }
  cout << s << endl;
  return 0;
}