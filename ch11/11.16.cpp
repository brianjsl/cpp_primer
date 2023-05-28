#include <iostream>
#include <map>
using namespace std;

int main() {
  map<int, int> a;
  int k, v;
  while (cin >> k >> v) {
    if (a.find(k) == a.end()) {
      a[k] = v;
    } else {
      a.find(k)->second = v;
    }
  }
  return 0;
}