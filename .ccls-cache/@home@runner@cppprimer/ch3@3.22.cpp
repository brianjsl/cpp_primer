#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<string> text = {"lorem", " ", "ipsum", " ", "dolar"};
  for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
    for (auto &c : *it) {
      c = toupper(c);
    }
  }
  for (auto c : text) {
    cout << c;
  }
  cout << endl;
  return 0;
}