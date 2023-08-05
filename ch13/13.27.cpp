#include <iostream>
#include <string>
using namespace std;

class HasPtr {
public:
  HasPtr(const string &s = std::string())
      : ps(new string(s)), i(0), use(new size_t(1)){};
  HasPtr(const HasPtr &orig);

  HasPtr &operator=(const HasPtr &orig);

  void changeS(const string &s) { *ps = s; }

  ~HasPtr() {
    if (--*use == 0) {
      delete ps;
      delete use;
    }
  }

  void print() { cout << *ps << endl; }

private:
  string *ps;
  int i;
  size_t *use;
};

HasPtr::HasPtr(const HasPtr &orig) {
  use = orig.use;
  ++*use;
  i = orig.i;
  ps = orig.ps;
};

HasPtr &HasPtr::operator=(const HasPtr &orig) {
  ++*orig.use;
  if (--*use == 0) {
    delete ps;
    delete use;
  }
  use = orig.use;
  ps = orig.ps;
  i = orig.i;
  return *this;
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