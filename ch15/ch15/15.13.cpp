#include <string>
using namespace std;

class base {
public:
	string name() { return basename;  }
	virtual void print(ostream& os) { os << basename;  } //prints the basename member of the class 

private:
	string basename;
};

class derived : public base {
public:
	void print(ostream& os) { print(os); os << " " << i;  } //this results in an infinite loop, since print(os) refers to the 
															//the print member of the base class. To get the print member of 
															//derived, we must use the scope operator.
private:
	int i;
};