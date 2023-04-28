#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<string> v;
  string s;

  while (cin >> s) {
    v.push_back(s);
  }
  for (auto &s : v) {
    for (auto &c : s)
      c = toupper(c);
  }
  for (decltype(v.size()) i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
    if (i % 8 == 7)
      cout << "\n";
  }
  cout << endl;
  return 0;
}