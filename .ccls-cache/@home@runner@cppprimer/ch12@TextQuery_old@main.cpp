#include "TextQuery.h"
#include <fstream>
#include <string>
using namespace std;

void runQueries(ifstream &infile) {
  TextQuery tq(infile);
  while (true) {
    cout << "enter a word to look for, or q to quit: ";
    string s;
    if (!(cin >> s) || s == "q")
      break;
    print(cout, tq.query(s)) << endl;
  }
}
int main(int argc, char *argv[]) {
  string f = argv[1];
  ifstream ifs(f);
  runQueries(ifs);
  return 0;
}