#include <stdexcept>
#include <vector>
using namespace std;

int add(int val1, int val2) { return val1 + val2; }

int subtract(int val1, int val2) { return val1 - val2; }

int multiply(int val1, int val2) { return val1 * val2; }

int divide(int val1, int val2) {
  if (val2 == 0) {
    throw runtime_error("Can't divide by zero!");
  }
  return val1 / val2;
}

int func(int val1, int val2);

vector<decltype(func) *> vec;

int main() {
  vec.push_back(add);
  vec.push_back(subtract);
  vec.push_back(multiply);
  vec.push_back(divide);
}