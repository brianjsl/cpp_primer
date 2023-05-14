#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

vector<string> readLines(const string &fn) {
  vector<string> lines;
  ifstream input(fn);
  string s;
  if (input) {
    while (getline(input, s)) {
      lines.push_back(s);
    }
  } else {
    cerr << "Invalid File" << endl;
  }
  return lines;
}

void print(const vector<string> &vec) {
  for (const auto v : vec) {
    cout << v << endl;
  }
}

int main() {
  string fn = "lorem_ipsum.txt";
  vector<string> flines = readLines(fn);
  print(flines);
  return 0;
}