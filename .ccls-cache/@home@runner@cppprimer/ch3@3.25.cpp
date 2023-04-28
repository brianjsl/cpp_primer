#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v(11, 0);
  int grade;
  while (cin >> grade) {
    if (grade <= 100) {
      ++v[grade / 10];
    }
  }

  for (auto i : v) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
