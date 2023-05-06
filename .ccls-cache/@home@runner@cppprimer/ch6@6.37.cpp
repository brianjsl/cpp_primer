#include <iostream>
#include <string>
using namespace std;

using ten_str = string[10];

ten_str &func1();

auto func2() -> string (&)[10];

string il[10] = {"hello"};
decltype(il) &func3();