#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
  vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  list<int> li;
  copy(vec.crbegin() + 2, vec.crbegin() + 7, back_inserter(li));
  for (const auto &l : li) {
    cout << l << " ";
  }
  cout << endl;
  return 0;
}