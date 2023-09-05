#include <vector>
#include <functional>
#include <iostream>
using namespace std;

int main() {
	vector<int> vec{ 2,3,4,5 };
	modulus<int> mod;
	
	int i = 7;
	for (const auto v : vec) {
		if (mod(i, v) == 0) {
			cout << i << " is divisible by " << v << endl;
			break;
		}
	}
	i = 50;
	for (const auto v : vec) {
		if (mod(i, v) == 0) {
			cout << i << " is divisible by " << v << endl;
			break;
		}
	}
	return 0;
}