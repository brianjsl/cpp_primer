#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<int> v1; // 0 values
  cout << v1.size() << endl;
  vector<int> v2(10); // 10 values, all 0
  cout << v2.size() << endl;
  vector<int> v3(10, 42); // 10 values, all 42
  cout << v3.size() << endl;
  vector<int> v4{10}; // 1 value, 10
  cout << v4.size() << endl;
  vector<int> v5{10, 42}; // 2 values, 10 and 42
  cout << v5.size() << endl;
  vector<string> v6{10}; // 10 values, all empty string
  cout << v6.size() << endl;
  vector<string> v7{10, "hi"}; // 10 values all "hi"
  cout << v7.size() << endl;
  return 0;
}