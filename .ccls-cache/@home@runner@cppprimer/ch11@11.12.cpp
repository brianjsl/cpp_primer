#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
  string s;
  int i;
  vector<pair<string, int>> vec;
  while (cin >> s >> i) {
    vec.push_back({s, i});
  }
  for (const auto &p : vec) {
    cout << p.first << ": " << p.second << endl;
  }
  return 0;
}