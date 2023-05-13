#include <vector>
using std::vector;

class Example {
public:
  //nonconst static members cannot be initialized in the class body
  // static double rate = 6.5;
  static double rate;

  //const static member can be initialized in the class body
  static const int vecSize = 20;

  //cant initialize nonconst static members in the class body.
  // static vector<double> vec(vecSize);
  static vector<double> vec;
};