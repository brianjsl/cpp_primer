#include <vector>
using namespace std;

class NoDefault {
public:
  NoDefault(int);
};

// Illegal, since no default constructor.
vector<NoDefault> vec(10);