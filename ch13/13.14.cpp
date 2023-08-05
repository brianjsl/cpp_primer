#include <iostream>
using namespace std;

struct numbered {
public:
  numbered() {
    mysn = syncount;
    ++syncount;
  }

  int mysn;

  static int syncount;
};

int numbered::syncount = 1;

void f(numbered s) { cout << s.mysn << endl; }

int main() {
  numbered a, b = a, c = b;
  f(a); // 1
  f(b); // 1
  f(c); // 1
  return 0;
}