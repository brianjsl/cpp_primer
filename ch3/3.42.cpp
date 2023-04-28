#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v{1, 3, 5, 5, 2};
  int arr[5];
  for (size_t i = 0; i < 5; ++i) {
    arr[i] = v[i];
  }
  for (auto c : arr) {
    cout << c << " ";
  }
  cout << endl;
  return 0;
}