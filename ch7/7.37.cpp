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
  Sales_data(std::string s = "") : bookNo(s) {}
  Sales_data(std::string s, unsigned cnt, double rev)
      : bookNo(s), units_sold(cnt), revenue(rev * cnt) {}
  Sales_data(std::istream &is) { read(is, *this); }
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

// Uses Sales_data(istream &is)
// Depends on cin
Sales_data first_item(std::cin);

int main() {
  Sales_data next; // default: uses Sales_data(string s=""), bookNo(""),
                   // units_sold(0), revenue(0.0)
  Sales_data last(
      "9-999-99999-9"); // uses Sales_data(string s), bookNo("9-999-99999-9")
  // units_sold(0), revenue(0.0)
}