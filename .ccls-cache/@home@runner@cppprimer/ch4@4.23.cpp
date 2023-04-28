#include <iostream>
#include <string>
using namespace std;

int main() {
  string s = "word";
  // Fails because conditional operator has lower priority than the equality
  // check so it checks if s+s[s.size()-1] == 's' first but cant compare
  // equality of a char and a string
  // string p1 = s + s[s.size() - 1] == 's' ? "" : "s";

  // A fix:
  string p1 = s + ((s[s.size() - 1] == 's') ? "" : "s");
  cout << p1 << endl;
}