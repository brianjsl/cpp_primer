#include <iostream>
#include <string>
using namespace std;

int main() {
  const string s = "Keep out!";
  // Yes, it is legal and c is a const char&
  for (auto &c : s) {
    /*...*/
  }
}