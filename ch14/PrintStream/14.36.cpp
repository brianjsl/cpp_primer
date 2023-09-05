#include "PrintStream.h"
#include <vector>
using std::string;
using std::vector;
using std::cin;

int main() {
	PrintStream ps;
	vector<string> v; 
	while (cin) {
		v.push_back(std::move(ps()));
	}
	for (const auto e : v) {
		std::cout << e << " ";
	}
	return 0;
}