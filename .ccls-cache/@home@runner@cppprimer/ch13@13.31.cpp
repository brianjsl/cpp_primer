#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class HasPtr {
  friend void swap(HasPtr &, HasPtr &);

public:
  HasPtr(const string &s = std::string(), int j = 0)
      : ps(new string(s)), i(j){};
  HasPtr(const HasPtr &orig) : ps(new string(*orig.ps)), i(orig.i){};

  HasPtr &operator=(const HasPtr &orig) {
    auto newp = new string(*orig.ps); // Copy first in case we assign to itself
    delete ps;
    ps = newp;
    i = orig.i;
    return *this;
  };

  bool operator<(const HasPtr &rhs) { return (i < rhs.i); };

  void changeS(const string &s) { *ps = s; }

  ~HasPtr() { delete ps; }

  void print() const { cout << *ps << " "; }

private:
  string *ps;
  int i;
};

void swap(HasPtr &lhs, HasPtr &rhs) {
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
  cout << "Swapped!" << endl;
}

int main() {
  HasPtr foo("foo", 11);
  HasPtr bar("bar", 7);
  HasPtr foobar("foobar", 13);
  HasPtr ussr("ussr", 5);
  vector<HasPtr> v({foo, bar, foobar, ussr});
  sort(v.begin(), v.end());
  for (const auto c : v) {
    c.print();
  }
  cout << endl;
}