#include <iostream>
#include <string>
using namespace std;

struct Person {
  string name, address;

  // Yes use const because we only want to read
  // the name/address not alter it or use it as
 
  string get_name() const { return name; };

  string get_addr() const { return address; };
}