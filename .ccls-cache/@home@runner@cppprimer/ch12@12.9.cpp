#include <memory>
using std::make_shared;
using std::shared_ptr;

int main() {
  int *q = new int(42), *r = new int(100);
  r = q; // r now points to the object at q while not freeing the 100 object it
         // initially pointed to
  auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
  r2 = q2; // r2 now points to the same object as q2 and since the reference
           // count for the 100 object reaches 0 it is destroyed.
}