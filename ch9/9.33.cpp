#include <vector>
using namespace std;
/*
The loop would be invalid because the begin pointer is now
invalidated since we did an insert. We will run into an invalid
pointer error.
*/
int main() {
  vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto begin = vi.begin();
  while (begin != vi.end()) {
    ++begin;
    vi.insert(begin, 42);
    ++begin;
  }
  return 0;
}