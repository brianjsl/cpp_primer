#include <iostream>
#include <string>
using namespace std;

class Employee {

public:
  Employee();
  Employee(const string &e_name);

  void print_id() { cout << id << endl; }

private:
  string name;
  string id;
  static int id_cnt;
};

Employee::Employee() { id = to_string(id_cnt++); }

Employee::Employee(const string &e_name) : name(e_name) {
  id = to_string(id_cnt++);
}

int Employee::id_cnt = 1;

int main() {
  Employee tom("tom");
  Employee rick("rick");

  tom.print_id();
  rick.print_id();
}