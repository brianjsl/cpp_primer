#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <utility>

class Quote
{
public:
	//constructors
	Quote() {
		//std::cout << "Quote()" << std::endl;
	};
	Quote(const std::string& book, double sales_price) : bookNo(book), price(sales_price) {
		//std::cout << "Quote(const std::string&, double)" << std::endl;
	};

	//copy constructors
	Quote(const Quote& q) : bookNo(q.bookNo), price(q.price) {
		//std::cout << "Quote(const Quote&)" << std::endl;
	};
	Quote& operator=(const Quote& rhs) {
		Quote q(rhs);
		bookNo = q.bookNo;
		price = q.price;
		//std::cout << "Quote& operator=(const Quote&)" << std::endl;
		return *this;
	};
	virtual ~Quote() {
		//std::cout << "~Quote()" << std::endl;
	};

	//move constructors
	Quote(Quote&& q) noexcept: bookNo(std::move(q.bookNo)), price(std::move(q.price)) {
		q.bookNo = "";
		q.price = 0;
		//std::cout << "Quote(Quote&&)" << std::endl;
	};
	Quote& operator=(Quote&&rhs) noexcept {
		if (this != &rhs) {
			bookNo = std::move(rhs.bookNo);
			price = std::move(rhs.price);
			rhs.bookNo = "";
			rhs.price = 0;
			//std::cout << "Quote& operator=(Quote&&rhs)" << std::endl;
		}
		return *this;
	};

	std::string isbn() const { return bookNo;  };

	//virtual members
	virtual double net_price(std::size_t n) const { return n * price;  };
	virtual void debug() const { std::cout << "bookNo: " << bookNo << ", price: " << price; };

	virtual Quote* clone() const& { return new Quote(*this); }
	virtual Quote* clone() const&& { return new Quote(std::move(*this)); }

private:
	std::string bookNo;
protected:
	double price = 0.0;
};

double print_total(std::ostream& os, const Quote& item, size_t n);
