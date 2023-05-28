#include <vector>
using namespace std;

// Error since the index 0 does not yet exist in
// the vector since unlike in a map subscripting
// does not add elements to a vector
int main() {
  vector<int> v;
  v[0] = 1;
}