#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

regex r("[[:digit:]]{3}-[[:digit:]]{4}-[[:digit:]]{4}");

struct PersonInfo {
  string name;
  vector<string> phones;
};

bool valid(const string &s) { return regex_match(s, r); }

int main(int argc, char *argv[]) {
  string line, word;
  vector<PersonInfo> people;
  istringstream record;
  ifstream is(argv[1]);
  ofstream os(argv[2]);

  while (getline(is, line)) {
    PersonInfo info;
    record.str(line);
    record >> info.name;
    while (record >> word) {
      info.phones.push_back(word);
    }
    people.push_back(info);
  }

  for (const auto &entry : people) {
    ostringstream formatted, badNums;
    for (const string &nums : entry.phones) {
      if (!valid(nums)) {
        badNums << " " << nums;
      } else {
        formatted << " " << nums;
      }
    }
    if (badNums.str().empty())
      os << entry.name << " " << formatted.str() << endl;
    else
      cerr << "input error: " << entry.name << " invalid number(s)"
           << badNums.str() << endl;
  }
  return 0;
}