#include <iostream>
#include <vector>
using namespace std;

int main() {
  int arr[5] = {1, 4, 1, 23, 3};
  for (int *p = arr; p != end(arr); ++p) {
    *p = 0;
  }
  for (auto c : arr) {
    cout << c << " ";
  }
  cout << endl;
}
