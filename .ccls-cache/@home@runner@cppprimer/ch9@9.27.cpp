#include <forward_list>
#include <iostream>
using namespace std;

void remove_odd(forward_list<int> &flist) {
  auto prev = flist.before_begin();
  auto curr = flist.begin();

  while (curr != flist.end()) {
    if (*curr % 2) {
      curr = flist.erase_after(prev);
    } else {
      prev = curr;
      ++curr;
    }
  }
}

void print(const forward_list<int> &flist) {
  for (const auto &i : flist) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  forward_list<int> flist = {1, 5, 13, 17, 8, 4, 23, 18, 6};
  remove_odd(flist);
  print(flist);
  return 0;
}