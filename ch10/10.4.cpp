/* The + addition used by 0 is integer addition and so the vaLue produced will
   be as a result of doing addition by ints. You should use 0.0 to get the
  correct type of addition. */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  vector<double> vec = {1.0, 2.3, 4.5, 6.7, 11.2, 2.1, 9.6};
  cout << accumulate(vec.cbegin(), vec.cend(), 0.0) << endl;
  return 0;
}