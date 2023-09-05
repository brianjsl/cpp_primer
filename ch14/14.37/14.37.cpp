#include "Equal.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main(int argc, char*argv[]) {
	if (argc < 2) std::cerr << "Not enough args" << std::endl;
	else {
		std::ifstream ifs(argv[1]);
		std::string s;
		std::getline(ifs, s, {});

		Equal e("the");
		
		std::istringstream iss(s);
		std::string tmp;
		std::string ret;
		while (iss >> tmp) {
			if (e(tmp)) {
				ret += "teh";
			}
			else {
				ret += tmp;
			}
			ret += ' ';
		}

		std::cout << ret << std::endl;
	}
	return 0;
}
