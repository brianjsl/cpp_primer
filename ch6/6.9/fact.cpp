#include "Chapter6.h"
#include<iostream>
using namespace std;

int fact(unsigned val) {
  if (val == 0 || val == 1) {
    return 1;
  }
  return val*fact(val-1);
}

