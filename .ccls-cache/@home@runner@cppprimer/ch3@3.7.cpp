#include <iostream>
#include <string>
using namespace std;

int main() {
  string s = "Blahblahblah";
  // Nothing will change since we dont have
  // a reference and instead we are just
  // creating new variables
  for (char c : s) {
    c = 'X';
  }
  cout << s << endl;
  return 0;
}