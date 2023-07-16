#include "TextQuery/TextQuery.h"
#include <fstream>
#include <string>
using namespace std;

void runQueries(ifstream &infile) {
  TextQuery tq(infile);
  string s;
  // There is literally no difference
  do {
    cout << "enter a word to look for, or q to quit: ";
    if (!(std::cin >> s) || s == "q")
      break;
    print(cout, tq.query(s)) << endl;
  } while (true);
}
int main(int argc, char *argv[]) {
  string f = argv[1];
  ifstream ifs(f);
  runQueries(ifs);
  return 0;
}