#include <string>

/*
Having individual copy-assignment and move-assignment operators is more efficient because
unlike in the copy and swap case, when you invoke a move assignment, you don't create a 
temporary lvalue that you "move" the rhs into, you just invoke an rvalue reference immedietly
so there is some time saved there.
*/
class HasPtr {
public:
	HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0);

	//copy constructors
	HasPtr(const HasPtr& p) : ps(new std::string(*p.ps)), i(p.i) {};
	HasPtr& operator=(const HasPtr&);
	~HasPtr() { delete ps };

	//move constructors
	HasPtr(HasPtr&& p) noexcept: ps(p.ps), i(p.i) {p.ps=0};
	HasPtr& operator=(HasPtr&&) noexcept; 
	
private:
	std::string* ps;
	int i;
};

HasPtr& HasPtr::operator=(const HasPtr& rhs) {
	auto newp = new std::string(*rhs.ps);
	delete ps;
	ps = newp;
	i = rhs.i;
	return *this;
}

HasPtr& HasPtr::operator=(HasPtr&& rhs) {
	if (this != &rhs) {
		ps = rhs.ps;
		i = rhs.i;
		rhs.ps = nullptr;
		rhs.i = 0;
	}
	return *this;
}
