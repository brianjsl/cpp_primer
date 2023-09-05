#pragma once
#include <iostream>

class Equal
{
public:
	Equal(const std::string& s) : s(s) {};

	bool operator()(std::string e) {
		return s == e;
	}

private:
	std::string s;
};

