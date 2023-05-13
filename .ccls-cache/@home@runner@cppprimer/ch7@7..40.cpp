#include <iostream>
// b)Date

class Date {
  friend void read(std::istream &, Date);

public:
  int year;
  int month;
  int day;
  // Set default to new years day of the current year
  Date(int yr = 2023, int mth = 1, int dy = 1)
      : year(yr), month(mth), day(dy) {}
  Date(std::istream &is) { read(is, *this); }
};

void read(std::istream &is, Date date) {
  is >> date.year >> date.month >> date.month;
}