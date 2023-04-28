#include <iostream>
using namespace std;

int main() {
  int n[5] = {1, 4, 2, 5, 8};
  int *p1 = n;
  int *p2 = &n[3];
  p1 += p2 - p1; // Increments p1 by how far apart p1 and p2 is,
                 // ie.to where p2 is so p1 and p2 now point to the
                 // same object. Always legal.
}