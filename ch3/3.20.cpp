#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<int> v;
  int i;
  while (cin >> i) {
    v.push_back(i);
  }

  int sum = 0;
  for (int i = 0; i < v.size() - 1; i++) {
    cout << v[i] + v[i + 1] << endl;
  }

  for (int i = 0; i < v.size() / 2; i++) {
    cout << v[i] + v[v.size() - i - 1] << endl;
  }
}