#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<vector<int>> ivec;   // creates a vector of vectors of ints
  vector<string> svec = ivec; // Illegal, since ivec is not of type vec<string>
  vector<string> svec(10, "null"); // creates a vector of 10 "null"s
  return 0;
}