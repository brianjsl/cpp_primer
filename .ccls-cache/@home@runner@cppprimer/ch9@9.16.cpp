#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
  vector<int> v1 = {1, 2, 3, 4, 5};
  list<int> v2 = {1, 2, 3, 4, 5};

  vector<int> v3(v2.begin(), v2.end());
  if (v1 == v3) {
    cout << "True" << endl;
  } else {
    cout << "False" << endl;
  }
  return 0;
}