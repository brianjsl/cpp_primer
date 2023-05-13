#include <iostream>

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
  // remove the default argument for s as this produces an error
  // since two default arguments
  Sales_data(std::string s) : bookNo(s) {}
  Sales_data(std::string s, unsigned cnt, double rev)
      : bookNo(s), units_sold(cnt), revenue(rev * cnt) {}
  // add default argument for cin
  Sales_data(std::istream &is = std::cin) { read(is, *this); }
  Sales_data &combine(const Sales_data &rhs);
  inline std::string isbn() const { return bookNo; };
};

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data res = lhs;
  res.combine(rhs);
  return res;
}

std::istream &read(std::istream &is, Sales_data &item) {
  double price;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
  os << item.isbn() << " " << item.units_sold << " " << item.revenue << " "
     << item.avg_price();
  return os;
}