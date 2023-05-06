#include <iostream>
#include <string>
using namespace std;

int main() {
  string s1, s2;
  cout << "Enter two strings: ";
  cin >> s1 >> s2;
  do {
    cout << ((s1 == s2)  ? "Equal"
             : (s1 < s2) ? "First one less"
                         : "Second one less")
         << endl;
    cout << "Enter two strings: ";
  } while (cin >> s1 >> s2);
  return 0;
}