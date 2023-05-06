#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>::const_iterator beg, vector<int>::const_iterator end) {
  if (beg == end) {
    return;
  }
  cout << *beg << " ";
  print(++beg, end);
}

int main() {
  vector<int> v = {3, 1, 2, 5, 6, 7, 2, 19};
  print(begin(v), end(v));
  cout << endl;
  return 0;
}