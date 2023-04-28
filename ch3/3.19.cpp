#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<int> ivec = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
  vector<int> ivec2(10, 42); // preferred way
  vector<int> ivec3;
  for (int i = 0; i < 10; ++i) {
    ivec.push_back(42);
  }
  return 0;
}