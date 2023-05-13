#include <iostream>
#include <string>
using namespace std;

class Person {
  friend istream &read(istream &is, Person p);

  // Member variables should be private and should only be changed
  // by the constructor when making the person
private:
  string name, address;

public:
  // Constructors
  Person() : name(""), address("") {}
  Person(const string &n) : name(n), address("") {}
  Person(const string &n, const string &addr) : name(n), address(addr) {}
  Person(istream &is);

  // Yes use const because we only want to read
  // the name/address not alter it or use it as

  string get_name() const { return name; };

  string get_addr() const { return address; };
};

istream &read(istream &is, Person p) {
  is >> p.name >> p.address;
  return is;
}

ostream &print(ostream &os, Person p) {
  os << "Name: " << p.get_name() << "\n"
     << "Address: " << p.get_addr();
  return os;
}

Person::Person(istream &is) { read(is, *this); }