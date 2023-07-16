// We can subscript using a map<type, type>::key_type. The subscript
// operator then returns a &map<type, type>::mapped_type (an lvalue).

#include <map>
using namespace std;

int main() {
  map<int, int> ma;
  map<int, int>::key_type k;
  map<int, int>::mapped_type val = ma[k];
}