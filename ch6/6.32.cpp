#include <iostream>
using namespace std;

// better code would use size_t
int &get(int *array, int index) { return array[index]; }

int main() {
  // empty initializes an array of 10 0s
  int ia[10];

  // changes the ith index to i
  for (int i = 0; i != 10; ++i) {
    get(ia, i) = i;
  }
}