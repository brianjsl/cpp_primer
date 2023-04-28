#include <iostream>
#include <vector>
using namespace std;

void print_v(vector<int> v) {
  for (auto it = v.cbegin(); it != v.cend(); ++it) {
    cout << *it << " ";
  }
  cout << endl << v.size() << endl;
}

void print_v_str(vector<string> v) {
  for (auto it = v.cbegin(); it != v.cend() && !it->empty(); ++it) {
    cout << *it << " ";
  }
  cout << endl << v.size() << endl;
}

int main() {
  vector<int> v1; // 0 values
  print_v(v1);
  vector<int> v2(10); // 10 values, all 0
  print_v(v2);
  vector<int> v3(10, 42); // 10 values, all 42
  print_v(v3);
  vector<int> v4{10}; // 1 value, 10
  print_v(v4);
  vector<int> v5{10, 42}; // 2 values, 10 and 42
  print_v(v5);
  vector<string> v6{10}; // 10 values, all empty string
  print_v_str(v6);
  vector<string> v7{10, "hi"}; // 10 values all "hi"
  print_v_str(v7);
  return 0;
}
