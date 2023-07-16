#include <memory>
#include <string>
using namespace std;

int main() {
  unique_ptr<string> p1(new string("Hello"));
  unique_ptr<string> p2(p1);
  unique_ptr<string> p3;
  p3 = p1;
}