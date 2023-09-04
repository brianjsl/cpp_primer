#include <string>
#include <iostream>

/*
The file will not compile because operator= is ambiguous. rhs and &&rhs
both take rvalues so there can only be one of the two functions.
*/
class HasPtr {
public:
	HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0) {};

	//copy constructors
	HasPtr(const HasPtr& p) : ps(new std::string(*p.ps)), i(p.i) {};
	HasPtr& operator=(HasPtr);
	~HasPtr() { delete ps; };

	//move constructors
	HasPtr(HasPtr&& p) noexcept : ps(p.ps), i(p.i) { p.ps = 0; };
	HasPtr& operator=(HasPtr&&) noexcept; 
	
private:
	std::string* ps;
	int i;
};

HasPtr& HasPtr::operator=(HasPtr rhs) {
	std::cout << "copy and swap" << std::endl;
	std::swap(*this, rhs);
	return *this;
}

HasPtr& HasPtr::operator=(HasPtr&& rhs) noexcept {
	std::cout << "move assignment" << std::endl;
	if (this != &rhs) {
		ps = rhs.ps;
		i = rhs.i;
		rhs.ps = nullptr;
		rhs.i = 0;
	}
	return *this;
}

int main() {
	HasPtr h1("h1");
	HasPtr h2;
	h2 = h1;
	return 0;
}
