#include <iostream>
#include <string>
using namespace std;

int main() {
  string s, currS, maxS;
  int cnt = 1, maxCnt = 1;
  cin >> currS;
  while (cin >> s) {
    if (s == currS) {
      ++cnt;
      if (cnt > maxCnt) {
        maxCnt = cnt;
        if (s != maxS) {
          maxS = s;
        }
      }
    } else {
      cnt = 1;
      currS = s;
    }
  }

  (maxCnt == 1) ? cout << "No duplicates" << endl
                : cout << "The maximum number of duplicates is " << maxCnt
                       << " with word " << maxS << endl;
  return 0;
}