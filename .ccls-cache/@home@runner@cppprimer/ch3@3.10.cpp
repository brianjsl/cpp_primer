#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  string removed;
  getline(cin, s);
  for (auto c : s) {
    if (!ispunct(c)) {
      removed += c;
    }
  }
  cout << removed << endl;
  return 0;
}