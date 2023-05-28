#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Date {
public:
  Date(const string &date);

  void print() { cout << month << "/" << day << "/" << year << endl; };

private:
  unsigned year;
  unsigned month;
  unsigned day;
  unordered_map<string, unsigned> month_map;
};

Date::Date(const string &date) {
  month_map = {
      {"January", 1}, {"Jan", 1},       {"Feburary", 2}, {"Feb", 2},
      {"March", 3},   {"Mar", 3},       {"April", 4},    {"Apr", 4},
      {"May", 5},     {"June", 6},      {"Jun", 6},      {"July", 7},
      {"Jul", 7},     {"August", 8},    {"Aug", 8},      {"September", 9},
      {"Sep", 9},     {"October", 10},  {"Oct", 10},     {"November", 11},
      {"Nov", 11},    {"December", 12}, {"Dec", 12}};
  istringstream i(date);
  vector<string> tokens;
  string s;
  while (i >> s) {
    tokens.push_back(s);
  }

  if (tokens.size() == 1) {
    string::size_type pos1 = s.find('/');
    month = stoi(s.substr(0, pos1));
    string::size_type pos2 = s.find('/', pos1 + 1);
    day = stoi(s.substr(pos1 + 1, pos2));
    year = stoi(s.substr(pos2 + 1, s.size()));
  }

  else if (tokens.size() == 3) {
    if (month_map.find(tokens[0]) != month_map.end()) {
      month = month_map[tokens[0]];
    } else {
      throw runtime_error("Not a valid date type!");
    }

    string::size_type pos1 = tokens[1].find(',');
    day = stoi(tokens[1].substr(0, pos1));

    year = stoi(tokens[2]);
  }

  else {
    throw runtime_error("Not a valid date type!");
  }
}

int main() {
  Date d1("1/1/1900");
  Date d2("January 2, 1900");
  Date d3("Jan 3, 1900");
  d1.print();
  d2.print();
  d3.print();
  return 0;
}