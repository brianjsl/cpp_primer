#include <iostream>
using namespace std;

int main() {
  int seqs = 0;
  string s;
  while (cin >> s) {
    for (auto i = s.begin(); i != s.end() - 1; ++i) {
      if (*i == 'f') {
        switch (*(i + 1)) {
        case 'f':
        case 'l':
        case 'i':
          ++seqs;
          break;
        default:
          break;
        }
      }
    }
  }
  cout << seqs << endl;
  return 0;
}