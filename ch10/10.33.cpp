#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
using namespace std;

int main(int argc, char *argv[]) {
  ifstream in_f(argv[1]);
  ofstream of_odd(argv[2]), of_even(argv[3]);

  istream_iterator<int> is(in_f), eof;
  while (is != eof) {
    if (*is % 2) {
      of_odd << *is << endl;
    } else {
      of_even << *is << endl;
    }
    ++is;
  }
  return 0;
}