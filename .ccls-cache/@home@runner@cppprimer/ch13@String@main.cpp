#include "String.h"
#include <iostream>
using namespace std;

int main() {
  String h = "hello";
  String w = "world";

  h.print();
  cout << endl;
  h = h + w;
  h.print();
  cout << endl;
  return 0;
}