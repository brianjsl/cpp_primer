#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
  istream_iterator<int> is(cin), eos;
  vector<int> tmp, unique;
  copy(is, eos, back_inserter(tmp));
  sort(tmp.begin(), tmp.end());
  unique_copy(tmp.begin(), tmp.end(), back_inserter(unique));
  for (const auto &v : unique) {
    cout << v << " ";
  }
  cout << endl;
  return 0;
}