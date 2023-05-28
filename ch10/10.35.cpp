#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void rprint(vector<int> &vec) {
  for (auto idx = --vec.cend(); idx + 1 != vec.cbegin(); --idx) {
    cout << *idx << " ";
  }
  cout << endl;
}

int main() {
  vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  rprint(vec);
  return 0;
}