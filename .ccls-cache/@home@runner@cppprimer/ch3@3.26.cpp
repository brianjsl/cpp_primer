#include <vector>
using namespace std;

int main() {
  int sought = 52;
  vector<int> text = {1, 3, 5, 9, 12, 52, 192};
  auto beg = text.begin(), end = text.end();
  // We cannot divide an iterator object, while end-beg
  // is an int so it can be divided
  auto mid = beg + (end - beg) / 2;
  while (mid != end && *mid != sought) {
    if (*mid < sought) {
      end = mid;
    } else {
      beg = mid + 1;
    }
    mid = beg + (end - beg) / 2;
  }
}