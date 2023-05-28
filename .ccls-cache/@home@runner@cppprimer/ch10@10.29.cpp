#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  vector<string> vec;
  ifstream i(argv[1]);
  istream_iterator<string> str_it(i), eof;
  copy(str_it, eof, back_inserter(vec));
  auto print = [](vector<string> &vec) {
    for (const auto &v : vec)
      cout << v << " ";
  };
  print(vec);
  cout << endl;
  return 0;
}