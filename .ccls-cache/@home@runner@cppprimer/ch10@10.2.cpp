#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

int main() {
  list<string> li;
  string s;
  while (cin >> s) {
    li.push_back(s);
  }

  cout << count(li.begin(), li.end(), "thing") << endl;
  return 0;
}