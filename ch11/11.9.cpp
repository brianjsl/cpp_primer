#include <list>
#include <map>
#include <string>
using namespace std;

int main() {
  map<string, list<int>> m;
  m["thing"] = {1, 3, 8};
  return 0;
}