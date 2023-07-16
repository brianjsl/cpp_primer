#include "StrBlob.h"
#include "StrBlobPtr.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  ifstream is(argv[1]); // Input File
  string s;
  StrBlob sb;

  while (is >> s) {
    sb.push_back(s);
  }

  StrBlobPtr curr_sbp(sb);
  for (size_t idx = 0; idx < sb.size(); ++idx) {
    cout << curr_sbp.deref() << " ";
    curr_sbp.incr();
  }
  cout << endl;
  return 0;
}