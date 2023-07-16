#include <iostream>

using namespace std;

int main() {
  // It cuts off once no more can be added
  char *s = new char[20];
  cin.get(s, 20);
  cout << s << endl;
  delete[] s;
  return 0;
}