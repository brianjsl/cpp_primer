#pragma once
#include <functional>
#include <vector>
#include <map>
#include <string>
#include <stdexcept>

class Calculator
{
public:
	Calculator() {
		binops = {
			{"+", std::plus<int>()},
			{"-", std::minus<int>()},
			{"*", std::multiplies<int>()},
			{"/", std::divides<int>()}
		};
	}
	Calculator& operator=(const Calculator&rhs) {
		auto ret = rhs;
		*this = ret;
		return ret;
	}
	~Calculator() = default;

	int operator()(int i, int j, std::string op) {
		if (binops.find(op) == binops.end())
			throw std::runtime_error("Not a valid op!");
		else if (op == "/" && j == 0)
			throw std::runtime_error("Can't divide by zero!");
		else {
			return binops[op](i, j);
		}
	}

private:
	std::map<std::string, std::function<int(int, int)>> binops;
};

