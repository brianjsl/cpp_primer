#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
using namespace std;

void print(const vector<int> &vec) {
  for (const auto &v : vec) {
    cout << v << " ";
  }
  cout << endl;
}

int main() {
  /*
  a) Illegal, since the vector vec doesn't have as many
  elements as that of lst. We can solve this by using a
  back_insertor_iterator which will add enough elements
  to vec.
  */
  vector<int> vec;
  list<int> lst;
  int i;
  while (cin >> i) {
    lst.push_back(i);
  }
  copy(lst.cbegin(), lst.cend(), back_inserter(vec));
  print(vec);

  /*
  b) Illegal since reserve doesn't change the size of vec
  so there is not enough space in the vector (it simply
  allots enough memory for the vector before a reassignment
  is required). The proper way to solve this would be to
  initialize it with 10 elements.
  */
  vector<int> vec2(10);
  fill_n(vec2.begin(), 10, 0);
  print(vec2);
  return 0;
}
