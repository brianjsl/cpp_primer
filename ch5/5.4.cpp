#include <iostream>
using namespace std;

int main() {
  string s;
  // Invalid since we have to define/initialize iter first
  // while (string::iterator iter != s.end())
  string::iterator iter = s.begin();
  while (iter != s.end()) {
    /*
     */
  }
  // Second example invalid because status is out of scope.
  // Can be fixed by putting it inside the while loop.
  while (bool status = find(word)) {
    if (!status) {
      /**/
    }
  }
}