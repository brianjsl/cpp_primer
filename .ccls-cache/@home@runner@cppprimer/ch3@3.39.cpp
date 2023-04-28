#include "string.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s1 = "blah";
  string s2 = "blah";
  if (s1 == s2) {
    cout << "s1 equals s2" << endl;
  } else {
    cout << "s1 is not equal to s2" << endl;
  }

  char c1[] = "blah";
  char c2[] = "blah";
  if (strcmp(c1, c2) == 0) {
    cout << "c1 equals c2" << endl;
  } else {
    cout << "c1 is not equal to c2" << endl;
  }
  return 0;
}