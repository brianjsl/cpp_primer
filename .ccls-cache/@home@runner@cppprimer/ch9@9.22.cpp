#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> l) {
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
  vector<int> iv = {1, 2, 5, 2, 7, 8, 9, 8, 4};
  vector<int>::iterator iter = iv.begin(), mid = iv.begin() + (iv.size() / 2);

  int some_val = 2;
  while (iter != mid) {
    // inserting corrupts current pointers to elements (ie. iter)
    // must update iterator
    if (*iter == some_val) {
      iter = iv.insert(iter, 2 * some_val);
      ++iter;
      //mid needs to be repositioned based on parity of size of iv
      if (iv.size() % 2 == 0) {
        mid = iv.begin() + (iv.size() / 2);
      } else {
        mid = iv.begin() + (iv.size()/2 + 1);
      }
    }
    ++iter;
  }
  print(iv);
  return 0;
}