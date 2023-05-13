#include <string>
using std::string;

typedef string Type;

// global scope type is used
// Type is a string
Type initVal();

class Exercise {
public:
  typedef double Type;

  // Both return type and parameter types
  // are double (class type)
  Type setVal(Type);

  // Double because class type.
  Type initVal();

private:
  int val;
};

// Not yet scoped so uses global scope Type
// which is string. Can be fixed by using the
// scope operator.

// Type Exercise::setVal(Type parm) {
//   val = parm + initVal();
//   return val;
// }

Exercise::Type Exercise::setVal(Type parm) {
  val = parm + initVal();
  return val;
}