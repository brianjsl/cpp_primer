#pragma once
#include <string>

class BoundTest
{
public:
	BoundTest(size_t min_size = -1, size_t max_size = -1) : min_size(min_size), max_size(max_size) {};

	bool operator()(const std::string& s) const {
		return (s.size() >= min_size) && (s.size() <= max_size);
		if (min_size == -1 && max_size > 0)
			return (s.size() <= max_size);
		else if (min_size != -1 && max_size == -1) {
			return (s.size() >= min_size);
		}
		else {
			return false;
		}
	}

private:
	size_t min_size;
	size_t max_size;
};

