#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

int main() {
  list<int> li = {1, 2, 4, 0, 5, 0, 17, 0, 6, 0, 3, 8};
  auto idx = find(li.crbegin(), li.crend(), 0);
  cout << *idx << endl;
  return 0;
}