#include <vector>
using namespace std;

int f();
vector<int> vi(100);
int &&r1 = f();  // rvalue reference since f() returns a nonreference type
int &r2 = vi[0]; // lvalue reference since vi[0] returns an lvalue and to get an
                 // rvalue we need conversion
int &r3 = r1;    // variable expressions are lvalues
int &&r4 =
    vi[0] * f(); // expressions are rvalues so we can use a rvalue reference