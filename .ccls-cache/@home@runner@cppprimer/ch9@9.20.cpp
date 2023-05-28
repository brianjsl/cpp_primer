#include <deque>
#include <iostream>
#include <list>
using namespace std;

void print(deque<int> l) {
  cout << "{";
  for (auto ix = l.cbegin(); ix != l.cend(); ++ix) {
    cout << *ix;
    if (next(ix) != l.cend()) {
      cout << ", ";
    } else {
      cout << "}" << endl;
    }
  }
}

int main() {
  list<int> li = {1, 2, 4, 6, 3};
  deque<int> even, odd;
  for (auto ix = li.cbegin(); ix != li.cend(); ++ix) {
    if (*ix % 2 == 0) {
      even.push_back(*ix);
    } else {
      odd.push_back(*ix);
    }
  }
  print(even);
  print(odd);
  return 0;
}