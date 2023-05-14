#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cerr;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

int main(int argc, char *argv[]) {
  vector<string> lines;
  string line;
  ifstream input(argv[1]);

  if (input) {
    while (getline(input, line)) {
      lines.push_back(line);
    }
  } else {
    cerr << "Invalid File!" << endl;
  }

  string word;
  for (const auto &s : lines) {
    istringstream is(s);
    while (is >> word) {
      cout << word << " ";
    }
    cout << endl;
  }
  return 0;
}