#include <iostream>
using namespace std;

int main() {
  int x[10];
  int *p = x;

  cout << sizeof(x) / sizeof(*x) << endl; // Value should be 10 since dividing
                                          //(number of elements in array)*(size
                                          // of elements) / (size of elements)
                                          //=number of elements in array
  cout << sizeof(p) / sizeof(*p) << endl; // p is a pointer to the first element
                                          // so it has size 8 while *p is an
                                          // int so it has size 4 so value = 2
  return 0;
}