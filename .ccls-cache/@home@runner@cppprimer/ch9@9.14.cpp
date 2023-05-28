#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

void print(vector<string> vec) {
  for (const auto &v : vec) {
    cout << v << " ";
  }
  cout << endl;
}
int main() {
  list<const char *> lchar = {"hello", "world", "this", "sucks"};
  vector<string> vec;
  vec.assign(lchar.begin(), lchar.end());
  print(vec);
  return 0;
}