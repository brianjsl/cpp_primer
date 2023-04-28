// We used prefix because we dont need the value returned
// and copying takes extra work
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> ivec = {1, 3, 2, 4, 5};
  vector<int>::size_type cnt = ivec.size();
  for (vector<int>::size_type ix = 0; ix != ivec.size(); ix--, cnt--) {
    ivec[ix] = cnt;
  }
  return 0;
}