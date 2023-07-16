#include <vector>
using namespace std;

typedef vector<int>::iterator iter;

bool findIdx(iter begin, iter end, int i) {
  for (; begin != end; ++begin) {
    if (*begin == i) {
      return true;
    }
  }
  return false;
}

int main() { return 0; }