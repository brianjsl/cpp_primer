#include <iostream>
#include <memory>
#include <string>
using namespace std;

int main() {
  size_t n = 20;
  allocator<string> a;
  auto const p = a.allocate(n);
  auto q = p;
  string s;
  while (cin >> s && q) {
    a.construct(q++, s);
  }

  while (q != p)
    a.destroy(--q);
  a.deallocate(p, n);
}