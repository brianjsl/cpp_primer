// It prints all the characters in ca, ie. prints
//"hello" with each charater on a new line.
#include <iostream>
using namespace std;

int main() {
  const char ca[] = {'h', 'e', 'l', 'l', 'o'};
  const char *cp = ca;
  while (*cp) {
    cout << *cp << endl;
    ++cp;
  }
  return 0;
}