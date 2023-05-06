#include <iostream>
using namespace std;

void print(const char *cp) {
  if (cp) {
    while (*cp) {
      cout << *cp++ << " ";
    }
  }
}

void print(const int *beg, const int *end) {
  while (beg != end) {
    cout << *beg++ << " ";
  }
}

void print(const int ia[], size_t size) {
  for (decltype(size) i = 0; i != size; ++i) {
    cout << *ia++ << " ";
  }
}

void print(int (&arr)[10]) {
  for (auto elem : arr) {
    cout << elem << " ";
  }
}

int main() {
  int i = 0, j[] = {0, 1};
  int k[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  print(k, 10);
  cout << endl;
  return 0;
}