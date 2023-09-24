#pragma once
#include "Disc_quote.h"
class Bulk_quote : public Disc_quote
{
public:
	using Disc_quote::Disc_quote; //inehrits non-default constructors

	Bulk_quote() {
		//std::cout << "Bulk_quote()" << std::endl;
	};
	
	//copy constructors
	Bulk_quote(const Bulk_quote& bq) : Disc_quote(bq) {
		//std::cout << "Bulk_quote(const Bulk_quote &bq)" << std::endl;
	};
	Bulk_quote& operator=(const Bulk_quote&rhs) {
		Disc_quote::operator=(rhs);
		//std::cout << "Bulk_quote& operator=(const Bulk_quote&rhs)" << std::endl;
		return *this;
	};
	~Bulk_quote() override = default;

	//move constructors
	Bulk_quote(Bulk_quote&& bq) : Disc_quote(std::move(bq)) {
		//std::cout << "Bulk_quote(Bulk_quote&&)" << std::endl;
	};
	Bulk_quote& operator=(Bulk_quote&& rhs) {
		Disc_quote::operator=(std::move(rhs));
		//std::cout << "Bulk_quote& operator=(Bulk_quote&&)" << std::endl;
	};

	double net_price(std::size_t) const override;

	virtual void debug() const override;

	virtual Bulk_quote* clone() const &override { return new Bulk_quote(*this); }
	virtual Bulk_quote* clone() const &&override { return new Bulk_quote(std::move(*this)); }
};

