#include "PrintStream.h"

std::string PrintStream::operator()() const {
	std::string ret;
	std::getline(is, ret, delim);
	return ret;
}
