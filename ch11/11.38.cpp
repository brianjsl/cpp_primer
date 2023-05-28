#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, string> buildMap(ifstream &map_file) {
  unordered_map<string, string> m;
  string word, replacement;
  while (map_file >> word && getline(map_file, replacement)) {
    if (replacement.size() > 1) {
      replacement = replacement.substr(1);
      m[word] = replacement;
    } else {
      throw runtime_error("Invalid map file!");
    }
  }
  return m;
}

const string &transform(const string &s,
                        const unordered_map<string, string> &m) {
  if (m.find(s) == m.end()) {
    return s;
  } else {
    return m.at(s);
  }
}

void word_transform(ifstream &map_file, ifstream &input) {
  string s;
  string word;
  unordered_map<string, string> m = buildMap(map_file);
  bool is_firstword;
  while (getline(input, s)) {
    istringstream is(s);
    is_firstword = true;
    while (is >> word) {
      if (is_firstword) {
        is_firstword = false;
      } else {
        cout << " ";
      }
      cout << transform(word, m);
    }
    cout << endl;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    throw runtime_error("Invalid number of arguments!");
  }
  ifstream input(argv[1]);
  ifstream map_file(argv[2]);
  word_transform(map_file, input);
  return 0;
}