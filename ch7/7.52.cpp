#include <string>

sturct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
}

//Brace list initialization of a a sales data class 
//This is legal in C++ 14, although illegal in C++ 11
//since we provide value initialization for units_sold
//and revenue
Sales_data item = {"978-0590353403", 25, 15.99};