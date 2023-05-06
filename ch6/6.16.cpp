#include <string>
using namespace std;

// Better to use a reference to const if not altering
// the string itself.
bool is_empty(const string &s) { return s.empty(); }