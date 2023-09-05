#include <string>
#include <iostream>

class Tenerary {
public:
	std::string operator()(bool, const std::string&, const std::string&);
};

std::string Tenerary::operator()(bool b, const std::string &first, const std::string &second) {
	if (b)
		return first;
	else
		return second;
}

int main() {
	Tenerary t;
	std::cout << t(3 < 1, "true", "not true") << std::endl;
	return 0;
}