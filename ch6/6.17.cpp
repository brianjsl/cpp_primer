#include <iostream>
#include <string>
using namespace std;

bool contains_capital(const string &s) {
  for (auto c : s) {
    if (isupper(c)) {
      return true;
    }
  }
  return false;
}

void lower_str(string &s) {
  for (auto &c : s) {
    c = tolower(c);
  }
}

int main() {
  if (contains_capital("Hello World")) {
    cout << "Hello World" << endl;
  }
  if (contains_capital("hello world")) {
    cout << "hello Wwrld" << endl;
  }
  string s = "Hello World";
  lower_str(s);
  cout << s << endl;
  return 0;
}