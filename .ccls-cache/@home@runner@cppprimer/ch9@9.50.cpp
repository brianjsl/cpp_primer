#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<string> vec = {"3.14", "1.2", "5.09", "3.7", "4.6", "8.2"};

  double sum = 0;
  for (auto c : vec) {
    double i = stod(c);
    sum += i;
  }
  cout << sum << endl;
  return 0;
}