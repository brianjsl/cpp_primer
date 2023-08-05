/*
  Yes we need to define our own copy constructors
  since we should not simply be able to copy a person
  including the id (id should be different)
  By the rule of three/five we should thus define our own
  desturctors as well
*/

#include <iostream>
#include <string>
using namespace std;

class Employee {

public:
  Employee();
  Employee(const string &e_name);

  // Copy constructors
  Employee(const Employee &);
  Employee &operator=(const Employee &);
  ~Employee();

  void print_id() { cout << id << endl; }

  void print_name() { cout << name << endl; }

private:
  string name;
  string id;
  static int id_cnt;
};

Employee::Employee() { id = to_string(id_cnt++); }

Employee::Employee(const string &e_name) : name(e_name) {
  id = to_string(id_cnt++);
}

Employee::Employee(const Employee &orig) : name(orig.name) {
  id = to_string(id_cnt++);
}

Employee &Employee::operator=(const Employee &orig) {
  name = orig.name;
  id = to_string(id_cnt++);
  return *this;
}

int Employee::id_cnt = 1;

int main() {
  Employee rick("rick");
  Employee rick2(rick);
  rick2.print_name();
}