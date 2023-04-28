#include <iostream>
#include <vector>
using namespace std;

int main() {
  bool is_equal = false;
  int arr1[5] = {1, 4, 2, 4, 3}, arr2[6] = {1, 4, 2, 4, 3, 7};
  auto arr1_beg = arr1, arr1_end = end(arr1);
  auto arr2_beg = arr2, arr2_end = end(arr2);

  if (arr1_end - arr1_beg == arr2_end - arr2_beg) {
    is_equal = true;
    while (arr1_beg < arr1_end && arr2_beg < arr2_end) {
      if (*arr1_beg != *arr2_beg) {
        is_equal = false;
        break;
      }
      ++arr1_beg;
      ++arr2_beg;
    }
  }
  if (is_equal) {
    cout << "Equal" << endl;
  } else {
    cout << "Not Equal" << endl;
  }
  return 0;
}