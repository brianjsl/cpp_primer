#include <iostream>
#include <list>
#include <vector>
using namespace std;

void print(vector<double> vec) {
  for (const auto &v : vec) {
    cout << v << " ";
  }
}

// You can initialize using iterators
int main() {
  list<int> l1 = {1, 2, 3, 4, 5};
  vector<int> v1 = {1, 2, 3, 4, 5, 6};
  vector<double> v2(l1.cbegin(), l1.cend());
  vector<double> v3(v1.cbegin(), v1.cend());
  print(v2);
  cout << endl;
  print(v3);
  cout << endl;
  return 0;
}