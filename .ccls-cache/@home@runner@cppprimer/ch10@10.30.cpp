#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
  istream_iterator<int> is(cin), eos;
  vector<int> vec;
  copy(is, eos, back_inserter(vec));
  sort(vec.begin(), vec.end());
  for (const auto &v : vec) {
    cout << v << " ";
  }
  cout << endl;
  return 0;
}