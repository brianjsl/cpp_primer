#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main() {
  auto sl1 = "Hello ";
  auto sl2 = "World!";
  char *cs = new char[strlen(sl1) + strlen(sl2) + 1];
  strcat(cs, sl1);
  strcat(cs, sl2);

  cout << cs << endl;
  delete[] cs;

  string s1(sl1);
  string s2(sl2);

  cout << s1 + s2 << endl;
  return 0;
}