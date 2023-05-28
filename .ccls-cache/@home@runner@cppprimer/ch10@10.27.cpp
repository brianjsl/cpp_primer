#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
  vector<int> vec = {1, 3, 3, 2, 6, 8, 9, 8, 1, 7, 12};
  list<int> li;
  unique_copy(vec.begin(), vec.end(), back_inserter(li));
  li.sort();
  for (const auto &l : li) {
    cout << l << " ";
  }
  cout << endl;
  return 0;
}