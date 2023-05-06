#include <string>
using namespace std;

/*
a)
int f() {
  string s;
  // ...
  return s; // Can't return a string if the signature is an int
}
*/

string f() {
  string s;
  return s;
}

// b)
// no return type
// f2(int i) {/* */}

void f2(int i) { /* */
}

// c)
// Missing curly brace and cant have duplicate parameter names
// Also need to return int value.
// int calc(int v1, int v1) /* */}

int calc(int v1, int v2) { return 0; }

// d)
// Need curly braces to define block
// double square(double x) return x*x;

double square(double x) { return x * x; }