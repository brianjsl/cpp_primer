#include<algorithm>
#include<iterator>
#include <iostream>
#include <vector>

class Foo {
public:
	//copy constructors
	Foo(std::vector<int> v): data(v) {};
	Foo& operator=(const Foo&)&;
	~Foo() {};

	Foo sorted()&&;
	Foo sorted() const&;

	void print() const {
		for (const auto v : data)
			std::cout << v << " ";
		std::cout << std::endl;
	}

private:
	std::vector<int> data;
};

Foo& Foo::operator=(const Foo& rhs)& {
	data.clear();
	std::copy(rhs.data.begin(), rhs.data.end(), std::back_inserter(data));
	return *this;
}

Foo Foo::sorted()&& {
	std::cout << "rvalue sorted" << std::endl;
	sort(data.begin(), data.end());
	return *this;
}

//Foo Foo::sorted() const& 
//	return Foo(*this).sorted();
//}

Foo Foo::sorted() const& {
	std::cout << "lvalue sorted" << std::endl;
	return Foo(*this).sorted();
}

int main() {
	Foo f1({ 5, 4, 3, 2, 1 });
	f1.sorted().print();
	return 0;
}
