#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

class Sales_data {

  friend std::istream &read(std::istream &is, Sales_data &item);
  friend std::ostream &print(std::ostream &os, const Sales_data &item);

private:
  std::string bookNo = "";
  unsigned units_sold = 0;
  double revenue = 0.0;

  inline double avg_price() const { return revenue / units_sold; };

public:
  // constructors
  Sales_data() = default;
  Sales_data(const std::string &s) : bookNo(s) {}
  Sales_data(const std::string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {}
  Sales_data(std::istream &is);
  Sales_data &combine(const Sales_data &rhs);
  inline std::string isbn() const { return bookNo; };
};

Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

std::istream &read(std::istream &is, Sales_data &item);

std::ostream &print(std::ostream &os, const Sales_data &item);
