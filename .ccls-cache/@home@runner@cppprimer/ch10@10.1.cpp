#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> vec;
  int i;
  while (cin >> i) {
    vec.push_back(i);
  }

  cout << count(vec.begin(), vec.end(), 3) << endl;
  return 0;
}