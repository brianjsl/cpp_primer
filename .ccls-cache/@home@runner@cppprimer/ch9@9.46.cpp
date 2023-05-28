#include <iostream>
#include <string>
using namespace std;

string add_prefix(string s, const string &prefix, const string &suffix) {
  s.insert(0, prefix);
  s.insert(s.length(), suffix);
  return s;
}

int main() {
  string name = "Brian";
  string prefix = "Mr. ", suffix = " PhD";
  cout << add_prefix(name, prefix, suffix) << endl;
  return 0;
}