#include <iostream>
// b)Date

class Date {
  friend void read(std::istream &, Date);

public:
  int month;
  int day;
  int year;
  // Set default to new years day of the current year
  Date(int yr = 2023) : year(yr) {}
  Date(int mth, int dy, int yr) : Date(yr) {
    month = mth;
    day = dy;
  }
  Date(std::istream &is) : Date() { read(is, *this); }
};

void read(std::istream &is, Date date) {
  is >> date.month >> date.day >> date.year;
}