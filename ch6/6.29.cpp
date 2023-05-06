#include <iostream>
#include <string>
using namespace std;
// You would use it but only to not copy values from big classes
void print(initializer_list<string> il) {
  for (auto i : il) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  print({"Hello", "World"});
  return 0;
}