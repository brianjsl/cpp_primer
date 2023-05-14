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

vector<string> readWords(const string &fn) {
  vector<string> words;
  ifstream input(fn);
  string s;
  if (input) {
    while (input >> s) {
      words.push_back(s);
    }
  } else {
    cerr << "Invalid File" << endl;
  }
  return words;
}

void print(const vector<string> &vec) {
  std::size_t i = 0;
  for (auto ix = vec.begin(); ix != vec.end(); ++ix) {
    if (i % 10 == 9) {
      cout << endl;
    }
    cout << *ix << " ";
    ++i;
  }
  cout << endl;
}

int main() {
  string fn = "lorem_ipsum.txt";
  vector<string> fwords = readWords(fn);
  print(fwords);
  return 0;
}