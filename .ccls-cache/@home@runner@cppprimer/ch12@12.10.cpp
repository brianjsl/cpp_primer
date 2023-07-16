#include <memory>
using std::shared_ptr;

void process(shared_ptr<int> ptr) {
  // use ptr
} // ptr goes out of scope

int main() {
  shared_ptr<int> p(new int(42));
  // Technically correct but verbose. Creates a new
  // shared ptr that points to p, incrementing the
  // reference count to 2 and then 3 when copied into
  // process. After the statement goes to 2.
  process(shared_ptr<int>(p));

  // Can be achived better with just the following
  process(p);
}