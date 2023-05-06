#include <iostream>
using namespace std;

size_t call() {
  static int var = 0;
  return var++;
}

int main() {
  for (int i = 0; i < 5; ++i)
    cout << call();
  return 0;
}