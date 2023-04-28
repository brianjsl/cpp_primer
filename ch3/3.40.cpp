#include "string.h"
#include <iostream>
using namespace std;

int main() {
  char s1[] = "blah";
  char s2[] = "blooh";
  char s3[15];
  strcpy(s3, s1);
  strcat(s3, " ");
  strcat(s3, s2);

  cout << s3 << endl;
}