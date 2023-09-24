#pragma once
#include "Quote.h"
#include <string>
#include <functional>
class Disc_quote :
    public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const std::string& book, double price, std::size_t qty, double disc) :
        Quote(book, price), quantity(qty), discount(disc) {};
    double net_price(std::size_t) const = 0; //virtual function

    std::pair<size_t, double> discount_policy() const { return { quantity, discount }; };

    //copy constructors
    Disc_quote(const Disc_quote& bq) : Quote(bq), quantity(bq.quantity), discount(bq.discount) {
        //std::cout << "Disc_quote(const Disc_quote&)" << std::endl;
    };
    Disc_quote& operator=(const Disc_quote&rhs) {
        Quote::operator=(rhs);
        quantity = rhs.quantity;
        discount = rhs.discount;
        //std::cout << "Disc_quote& operator=(const Disc_quote&)" << std::endl;
        return *this;
    };
    ~Disc_quote() override = default;

    //move constructors
    Disc_quote(Disc_quote&& dq) : Quote(std::move(dq)), quantity(std::move(dq.quantity)), discount(std::move(dq.discount)) {
        quantity = discount = 0;
        //std::cout << "Disc_quote(Disc_quote&&)" << std::endl;
    };
    Disc_quote& operator=(Disc_quote&& rhs) {
        if (this != &rhs) {
            Quote::operator=(std::move(rhs));
            quantity = std::move(rhs.quantity);
            discount = std::move(rhs.discount);
        }
        //std::cout << "Disc_quote& operaor=(Disc_quote&&)" << std::endl;
        return *this;
    };

protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

