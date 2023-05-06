#include <iostream>
using namespace std;

void print(char *argv[]) {
  ++argv;
  while (*argv) {
    while (**argv) {
      cout << *(*argv)++;
    }
    cout << endl;
    ++argv;
  }
}

int main(int argc, char *argv[]) {
  print(argv);
  return 0;
}