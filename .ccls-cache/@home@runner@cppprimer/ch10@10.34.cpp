#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void rprint(vector<int> &vec) {
  for (auto idx = vec.crbegin(); idx != vec.crend(); ++idx) {
    cout << *idx << " ";
  }
  cout << endl;
}

int main() {
  vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  rprint(vec);
  return 0;
}