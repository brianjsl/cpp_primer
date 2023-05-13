#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

struct Sales_data {

  // constructors
  Sales_data() : bookNo(""), units_sold(0), revenue(0.0) {}
  Sales_data(const std::string &s) : bookNo(s) {}
  Sales_data(const std::string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {}
  Sales_data(std::istream &is);

  inline std::string isbn() const { return bookNo; };

  inline double avg_price() const { return revenue / units_sold; };

  Sales_data &combine(const Sales_data &rhs);

  std::string bookNo = "";
  unsigned units_sold = 0;
  double revenue = 0.0;
};

Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

std::istream &read(std::istream &is, Sales_data &item);

std::ostream &print(std::ostream &os, const Sales_data &item);