#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::string;

istream &func(istream &is) {
  auto old_state = is.rdstate();
  is.clear();
  string s;
  while (is >> s) {
    cout << s << endl;
  }
  is.clear();
  is.setstate(old_state);
  return is;
}

