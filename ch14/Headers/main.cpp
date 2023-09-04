#include "Date.h"
#include "StrVec.h"
#include "StrBlob.h"
#include "String.h"
#include <iostream>
#include <initializer_list>
using namespace std;

int main() {
	Date d("8/23/2023");
	Date d2("8/22/2023");
	std::cout << ((d < d2) ? "Day 1 is less" : "Day 2 is less") << std::endl;

	StrVec svec1({"hello", "world"}); 
	StrVec svec2({"hello", "worlds"});
	std::cout << ((svec1 == svec2) ? "StrVecs Equal" : "StrVecs Not Equal") << std::endl;

	StrBlob sblob1({ "hello", "world" });
	StrBlob sblob2({ "hello", "worlds"});
	std::cout << ((sblob1 == sblob2) ? "StrBlobs Equal" : "StrBlobs Not Equal") << std::endl;

	String s1("hello");
	String s2("hellp");
	std::cout << ((s1 < s2) ? "s1 smaller" : "s2 geq") << std::endl;

	return 0;
}