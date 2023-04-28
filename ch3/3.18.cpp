#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<int> ivec;
  ivec[0] = 42; // Illegal, can't index into an element
                // of a vector that doesn't exist
                // Proper way -> use push_back
}