#include <fstream>
#include <initializer_list>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> make_lines(ifstream &infile) {
  string line;
  vector<string> lines_res;
  while (getline(infile, line, '\n')) {
    lines_res.push_back(line);
  }
  return lines_res;
}

map<string, set<size_t>> make_word_db(vector<string> &lines) {
  string word;
  size_t line_no = 1;
  map<string, set<size_t>> word_db;

  for (const auto line : lines) {
    istringstream line_stream(line);
    while (line_stream >> word) {
      if (word_db.find(word) == word_db.end()) {
        word_db[word] = set<size_t>();
      }
      word_db[word].insert(line_no);
    }
    ++line_no;
  }

  return word_db;
}

ostream &print(ostream &os, string &s, vector<string> &lines,
               map<string, set<size_t>> word_db) {
  const auto which_lines = word_db[s];
  cout << s << " occurs " << which_lines.size() << " times\n";
  for (const auto line_no : which_lines) {
    cout << "\t(line " << line_no << ") " << lines[line_no - 1] << endl;
  }
  return os;
}

void runQueries(ifstream &infile) {
  vector<string> lines = make_lines(infile);
  map<string, set<size_t>> word_db = make_word_db(lines);
  while (true) {
    cout << "enter a word to look for, or q to quit: ";
    string s;
    if (!(cin >> s) || s == "q")
      break;
    print(cout, s, lines, word_db) << endl;
  }
}

int main(int argc, char *argv[]) {
  string f = argv[1];
  ifstream ifs(f);
  runQueries(ifs);
  return 0;
}