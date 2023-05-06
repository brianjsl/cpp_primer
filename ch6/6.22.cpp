#include <iostream>
using namespace std;

void swap(void *val1, void *val2) {
  void *temp = val2;
  val2 = val1;
  val1 = temp;
}

int main() {
  int i = 3, j = 4, *pi = &i, *pj = &j;
  swap(pi, pj);
  cout << *pi << " " << *pj << endl;
  return 0;
}