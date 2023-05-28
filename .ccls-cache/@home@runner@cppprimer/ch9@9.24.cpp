#include <iostream>
#include <vector>

using namespace std;
int main() {
  // throws a segfault (since accessing illegal memory)
  // or if val2 first, then throws an out_of_range
  vector<int> v;
  int val1 = v[0];
  int val2 = v.at(0);
  int val3 = v.front();
  int val4 = *v.begin();
  cout << val1 << " " << val2 << " " << val3 << " " << val4 << endl;
  return 0;
}