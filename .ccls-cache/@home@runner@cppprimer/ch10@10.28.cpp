#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

void print(deque<int> &vec) {
  for (const auto &v : vec) {
    cout << v << " ";
  }
  cout << endl;
}
int main() {
  vector<int> vec;
  deque<int> v1, v2, v3;
  for (int i = 1; i <= 9; ++i) {
    vec.push_back(i);
  }
  copy(vec.begin(), vec.end(), back_inserter(v1));
  copy(vec.begin(), vec.end(), front_inserter(v2));
  copy(vec.begin(), vec.end(), inserter(v3, v3.begin()));
  print(v1);
  print(v2);
  print(v3);
}