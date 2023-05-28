#include <iostream>
#include <list>
#include <vector>
using namespace std;

void print(vector<int> vec) {
  if (vec.empty()) {
    cout << "{}";
  } else {
    cout << "{";
    for (auto idx = vec.cbegin(); idx != vec.cend(); ++idx) {
      cout << *idx;
      if (idx != vec.cend() - 1) {
        cout << ", ";
      } else {
        cout << "}";
      }
    }
  }
}

void print(list<int> vec) {
  if (vec.empty()) {
    cout << "{}";
  } else {
    cout << "{";
    for (auto idx = vec.cbegin(); idx != vec.cend(); ++idx) {
      cout << *idx;
      if (idx != prev(vec.cend())) {
        cout << ", ";
      } else {
        cout << "}";
      }
    }
  }
}
int main() {
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  vector<int> vec(ia, ia + 11);
  list<int> ls(ia, ia + 11);
  auto vi = vec.begin();
  auto li = ls.begin();

  while (li != ls.end()) {
    if (*li % 2 == 1) {
      li = ls.erase(li);
    } else {
      ++li;
    }
  }

  while (vi != vec.end()) {
    if (*vi % 2 == 0) {
      vi = vec.erase(vi);
    } else {
      ++vi;
    }
  }

  print(vec);
  cout << endl;
  print(ls);
  cout << endl;
  return 0;
}