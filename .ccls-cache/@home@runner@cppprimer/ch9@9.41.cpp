#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<char> vc = {'h', 'e', 'l', 'l', 'o'};
  string s(vc.begin(), vc.end());
  cout << s << endl;
  return 0;
}