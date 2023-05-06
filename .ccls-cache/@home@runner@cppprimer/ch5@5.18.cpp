#include <iostream>
#include <vector>
using namespace std;

int main() {
  // forgot to add curly braces
  do {
    int v1, v2;
    cout << "Please enter two numbers to sum: ";
    if (cin >> v1 >> v2)
      cout << "Sum is: " << v1 + v2 << endl;
  } while (cin);

  // Can't declare value inside while statement
  int ival = get_response();
  do {
    ival = get_response();
  } while (ival);

  // Can't define value inside do statement either
}