#include <vector>
using namespace std;

/*
This will return an infinite loop since we do not increment
twice so if we find an odd value and we insert since iter is
only updated to the element before the current element and we
increment we return to the original value which repeats the loop
forever.
*/
int main() {
  vector<int> vi = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto iter = vi.begin();
  while (iter != vi.end()) {
    if (*iter % 2) {
      iter = vi.insert(iter, *iter);
    }
    ++iter;
  }
}