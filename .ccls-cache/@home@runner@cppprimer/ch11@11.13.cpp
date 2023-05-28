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
    // way one
    vec.push_back({s, i});

    // way two
    pair<string, int> p;
    p.first = s;
    p.second = i;
    vec.push_back(p);

    // way three
    vec.push_back(make_pair(s, i));
    // way one and three are easiest to write since they are fast (lol)
  }
  for (const auto &p : vec) {
    cout << p.first << ": " << p.second << endl;
  }
  return 0;
}