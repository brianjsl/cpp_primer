#include <iostream>
#include <string>
using namespace std;

class HasPtr {
public:
  HasPtr(const string &s = std::string()) : ps(new string(s)), i(0){};
  HasPtr(const HasPtr &orig) : ps(new string(*orig.ps)), i(orig.i){};

  HasPtr &operator=(const HasPtr &orig) {
    auto newp = new string(*orig.ps); // Copy first in case we assign to itself
    delete ps;
    ps = newp;
    i = orig.i;
    return *this;
  };

  void changeS(const string &s) { *ps = s; }

  ~HasPtr() { delete ps; }

  void print() { cout << *ps << endl; }

private:
  string *ps;
  int i;
};

int main() {
  HasPtr a("blah");
  HasPtr b;
  b = a;
  b.changeS("thing");
  a.print();
  b.print();
  a.print();
}