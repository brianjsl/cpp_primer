#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  multimap<string, string> works = {{"Glen", "Boo"},
                                    {"Glen", "Blah"},
                                    {"Glen", "Foo"},
                                    {"Glen", "Bar"},
                                    {"Stephen King", "It"}};
  auto pos = works.find("Glen");
  if (pos != works.end()) {
    works.erase(pos);
  }
  for (const auto &w : works) {
    cout << w.first << ": " << w.second << endl;
  }
  return 0;
}
