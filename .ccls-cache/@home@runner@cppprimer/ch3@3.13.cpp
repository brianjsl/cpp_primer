#include <string>
#include <vector>
using namespace std;

int main() {
  vector<int> v1;              // 0 values
  vector<int> v2(10);          // 10 values, all 0
  vector<int> v3(10, 42);      // 10 values, all 42
  vector<int> v4{10};          // 1 value, 10
  vector<int> v5{10, 42};      // 2 values, 10 and 42
  vector<string> v6{10};       // 10 values, all empty string
  vector<string> v7{10, "hi"}; // 10 values all "hi"
  return 0;
}