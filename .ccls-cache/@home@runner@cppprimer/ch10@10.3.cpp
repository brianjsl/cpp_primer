#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  vector<int> vec = {1, 3, 4, 6, 11, 2, 9};
  cout << accumulate(vec.cbegin(), vec.cend(), 0) << endl;
  return 0;
}