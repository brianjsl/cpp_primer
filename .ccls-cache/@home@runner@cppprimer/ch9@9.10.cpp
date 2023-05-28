#include <vector>
using namespace std;

int main() {
  vector<int> v1;
  const vector<int> v2;
  // This a vector<int>::iterator
  auto it1 = v1.begin();
  // This is a vector<int>::const_iterator
  auto it2 = v2.begin();
  // This is a vector<int>::const_iterator
  auto it3 = v1.cbegin();
  // This is a vector<int>::const_iterator
  auto it4 = v2.cbegin();
}