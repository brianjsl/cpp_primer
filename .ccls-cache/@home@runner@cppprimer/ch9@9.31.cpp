#include <forward_list>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

void odd_even_fn(list<int> &li) {
  /*
  The loop will not work on a list because you can not add twice to a
  list iterator element. You must instead increment twice.
  */
  auto iter = li.begin();
  while (iter != li.end()) {
    if (*iter % 2) {
      iter = li.insert(iter, *iter);
      ++iter;
      ++iter;
    } else
      iter = li.erase(iter);
  }
}

void odd_even_fn(forward_list<int> &fli) {
  /*
  The function doesn't work on forward lists since forward lists don't
  support insert (along with pointer addition). You instead need to use
  two pointers one to the element before and then use insert_after.
  */
  auto prev = fli.before_begin();
  auto curr = fli.begin();

  while (curr != fli.end()) {
    if (*curr % 2) {
      curr = fli.insert_after(prev, *curr);
      ++curr;
      prev = curr;
      ++curr;
    } else {
      curr = fli.erase_after(prev);
    }
  }
}

void print(const forward_list<int> &flist) {
  for (const auto &i : flist) {
    cout << i << " ";
  }
  cout << endl;
}

void print(const list<int> &list) {
  for (const auto &i : list) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  list<int> li(vi.begin(), vi.end());
  forward_list<int> fli(vi.begin(), vi.end());
  odd_even_fn(li);
  odd_even_fn(fli);
  print(li); 
  print(fli);
}