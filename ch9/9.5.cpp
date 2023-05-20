#include <vector>
using namespace std;

typedef vector<int>::iterator iter;

iter findIdx(iter begin, iter end, int i) {
  for (; begin != end; ++begin) {
    if (*begin == i) {
      return begin;
    }
  }
  return end;
}

int main() { return 0; }