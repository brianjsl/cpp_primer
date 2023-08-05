#include <iostream>
using namespace std;

struct numbered {
public:
  numbered() {
    mysn = syncount;
    ++syncount;
  }

  numbered(const numbered &orig) {
    mysn = syncount;
    ++syncount;
  }

  int mysn;

  static int syncount;
};

int numbered::syncount = 1;

void f(numbered s) { cout << s.mysn << endl; }

int main() {
  numbered a, b = a, c = b; // 1, 2, 3
  f(a);                     // 4
  f(b);                     // 5
  f(c);                     // 6
  return 0;
}