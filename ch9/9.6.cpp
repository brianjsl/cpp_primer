#include <list>
using namespace std;

int main() {
  list<int> lst1;

  // Error
  list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
  // Can't compare two itertors by < or > only by checking equality
  // through !=
  //  while (iter1 < iter2) {
  //    /* */
  //  };

  while (iter1 != iter2) {
    /* */
  };
  return 0;
}