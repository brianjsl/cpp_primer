#include "BoundTest.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
using std::ifstream;
using std::istringstream;
using std::getline;
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main38(int argc, char* argv[]) {
	ifstream ifs(argv[1]);
	vector<string> vec;
	string s;
	for (string line; getline(ifs, line, '\n'); ) {
		istringstream iss(line);
		while (iss >> s) {
			vec.push_back(s);
		}
	}

	BoundTest b(1,10);

	int cnt = 0;
	for (const auto i : vec) {
		if (b(i))
			++cnt;
	}
	cout << "There are " << cnt << " words with size between 1 and 10." << endl;
	return 0;
}
