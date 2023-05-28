#include <vector>
using namespace std;

int main() {
  vector<int> c = {3};
  if (!c.empty()) {
    auto val = *c.begin(); // 3
    auto val2 = c.front(); // Also 3
    auto last = c.end();   // Nonexistent value
    auto val3 = (--last);  // 3
    auto val4 = c.back();  // 3
    // In this case val1=val2=val3=val4=c[0]
  }
}