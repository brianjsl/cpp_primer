#include <memory>
using namespace std;

int main() {
  int ix = 1024, *pi = &ix, *pi2 = new int(2048);
  typedef unique_ptr<int> IntP;
  IntP p0(ix);  // Illegal, constructor needs to be a pointer binded by new
  IntP p1(pi);  // Also Illegal, needs to be dynamically allocated memory
  IntP p2(pi2); // Legal
  IntP p3(&ix); // Illegal, same reason as b
  IntP p4(new int(2048)); // Legal
  IntP p5(p2.get());      // Will compile but shouldn't be used.
                     // This gets the raw pointer from p2, and assigns it to p5.
                     // Both will free the same memory (twice).
}