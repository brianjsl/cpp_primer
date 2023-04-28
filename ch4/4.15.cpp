#include <iostream>
using namespace std;

int main() {
  double dval;
  int ival;
  int *pi;
  // dval = ival = pi = 0; //Illegal since pi is a int* which cannot be convert
  // to int
  dval = ival = 0;
  pi = 0;
  return 0;
}