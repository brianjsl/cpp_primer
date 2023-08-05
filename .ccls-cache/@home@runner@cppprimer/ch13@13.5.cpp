#include <string>
using namespace std;

class HasPtr {
public:
  HasPtr(const string &s = std::string()) : ps(new string(s)), i(0){};
  HasPtr(const HasPtr &orig) : ps(new string), i(orig.i) { *ps = *orig.ps; };

private:
  string *ps;
  int i;
};