#pragma once
#include <stdexcept>
#include <string>

class Sales_data {

    friend std::istream& operator>>(std::istream& is, Sales_data& item);
    friend std::ostream& operator<<(std::ostream& os, const Sales_data& item);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);

private:
    std::string bookNo = "";
    unsigned units_sold = 0;
    double revenue = 0.0;

    inline double avg_price() const { return revenue / units_sold; };

public:
    // constructors
    Sales_data() = default;
    Sales_data(const std::string& s) : bookNo(s) {}
    Sales_data(const std::string& s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(p* n) {}
    Sales_data(std::istream& is);
    Sales_data& combine(const Sales_data& rhs);
    inline std::string isbn() const { return bookNo; };

    Sales_data& operator+=(const Sales_data&);
    Sales_data& operator=(std::string);

    explicit operator std::string() const {
        return bookNo;
    }

    explicit operator double() const {
        return revenue;
    }
};


