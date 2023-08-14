#include "String/String.h"
#include <vector>
using namespace std;

int main() {
  vector<String> vi;
  // Six times. There is a copy constructor used for each
  // variable created (since we copy by value to the entry in the vector
  // the temporary created). Then, there is a copy constructor used for
  // each of the reallocates since our String class does not define a
  // move constructor.
  vi.push_back("One");
  vi.push_back("Two");
  // vi.push_back("Three");
  return 0;
}
