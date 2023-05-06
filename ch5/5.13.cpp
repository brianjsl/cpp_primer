#include <iostream>
#include <vector>
using namespace std;

unsigned some_value() { return 3; }

char next_text() { return 'a'; }

unsigned get_value() { return 1; }

int get_num() { return 13; }

int main() {
  unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
  char ch = next_text();
  switch (ch) {
  case 'a':
    aCnt++;
    break; // forgot to break
  case 'e':
    eCnt++;
    break;
  default:
  case 'i':
    iouCnt++;
    break;
  }

  unsigned index = some_value();
  vector<int> ivec = {1, 4, 3, 5, 2};

  unsigned ix; // needs initialization out of switch
  switch (index) {
  case 1:
    ix = get_value();
    ivec[ix] = index;
    break;
  default:
    ix = ivec.size() - 1;
    ivec[ix] = index;
    break;
  }

  unsigned evenCnt = 0, oddCnt = 0;
  int digit = get_num() % 10;
  switch (digit) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 9: // Needs individual case label
    oddcnt++;
    break;
  case 0: // Digit cant be 10
  case 2:
  case 4:
  case 6:
  case 8:
    evenCnt++;
    break;
  }

  const unsigned ival = 512, jval = 1024, kval = 4096;
  unsigned bufsize;
  unsigned swt = get_bufCnt();
  switch (swt) {
  case ival: // nonconst as case label
    bufsize = ival * sizeof(int);
    break;
  case jval:
    bufsize = jval * sizeof(int);
    break;
  case kval:
    bufsize = kval * sizeof(int);
    break;
  }
}