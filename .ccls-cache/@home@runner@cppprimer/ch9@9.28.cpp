#include <forward_list>
#include <iostream>
#include <string>
using namespace std;

void insert_string(forward_list<string> &flist, const string &s1,
                   const string &s2) {
  auto curr = flist.begin();

  while (curr != flist.end()) {
    if (*curr == s1 || next(curr) == flist.end()) {
      curr = flist.insert_after(curr, s2);
      break;
    }
    ++curr;
  }
}

void print(const forward_list<string> &flist) {
  for (const auto &i : flist) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  forward_list<string> flist = {"I", "hate", "Korean", "army", "lol"};
  insert_string(flist, "thing", "love");
  print(flist);
  return 0;
}