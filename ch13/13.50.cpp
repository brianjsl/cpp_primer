#include "String/String.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<String> vi;
	//There should only be copies when the first temporary object is created. (Basic constructor)
	//After that, the vector should use the move constructor (the move constructor) for all future
	//operations, including during reallocation.
	vi.push_back("One");
	vi.push_back("Two");
	vi.push_back("Three");
	return 0;
}