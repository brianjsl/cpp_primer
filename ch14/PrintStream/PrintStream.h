#pragma once
#include <iostream>
#include <string>

class PrintStream
{
public:
	PrintStream(std::istream& is = std::cin, char delim = '\n') : is(is), delim(delim) {};

	std::string operator()() const;

private:
	std::istream& is;
	char delim;
};

