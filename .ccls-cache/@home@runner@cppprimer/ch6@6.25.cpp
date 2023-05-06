#include <iostream>
#include <string>
using namespace std;

void concat_s(string &s, char *args[]) {
  ++args;
  while (*args) {
    while (**args) {
      s.push_back(*(*args)++);
    }
    ++args;
  }
}

int main(int argc, char *argv[]) {
  string s = "";
  // concat_s(s, argv);
  concat_s(s, argv);
  cout << s << endl;
  return 0;
}