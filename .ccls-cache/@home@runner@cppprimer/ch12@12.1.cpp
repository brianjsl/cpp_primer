#include "StrBlob.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
  StrBlob b1;
  {
    StrBlob b2 = {"a", "an", "the"}; // Creates a shared vector<string>
    b1 = b2; // b1 also now points to the same vector, a copy of b2 is created
             // and destroyed
    b2.push_back("about"); // b2 and b1 both point to a vector with 4 elements
  } // b2 is destroyed and thus there is only one pointer, b1 which points to a
    // vector of 4 elements while b2 doesn't exist
  cout << b1.size() << endl;
}