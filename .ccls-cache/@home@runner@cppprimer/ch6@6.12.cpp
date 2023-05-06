#include <iostream>
using namespace std;

// Easier since less copying is needed
void swap(int &val1, int &val2) {
  int temp = val2;
  val2 = val1;
  val1 = temp;
}

int main() {
  int i = 32, j = 40;
  swap(i, j);
  cout << i << " " << j << endl;
  return 0;
}