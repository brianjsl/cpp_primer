#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(vector<char> vec) {
  for (const auto &c : vec) {
    cout << c << " ";
  }
  cout << endl;
}

int main() {
  string s("ab2c3d7R4E6");
  vector<char> num_vec, alpha_vec;
  string num = "0123456789";
  string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

  string::size_type pos = 0;
  while ((pos = s.find_first_of(alpha, pos)) != string::npos) {
    alpha_vec.push_back(s[pos]);
    ++pos;
  }

  pos = 0;
  while ((pos = s.find_first_of(num, pos)) != string::npos) {
    num_vec.push_back(s[pos]);
    ++pos;
  }

  print(num_vec);
  print(alpha_vec);
}