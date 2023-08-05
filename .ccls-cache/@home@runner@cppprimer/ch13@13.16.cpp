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

void f(const numbered &s) { cout << s.mysn << endl; }

int main() {
  numbered a, b = a, c = b; // 1, 2, 3
  f(a);                     // 1
  f(b);                     // 2
  f(c);                     // 3
  return 0;
}