#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Families {
public:
  void add_family(string family) { fam_list[family] = {}; }
  void add_family(string family, vector<pair<string, string>> child_list) {
    fam_list[family].insert(fam_list[family].end(), child_list.begin(),
                            child_list.end());
  }
  void add_child(string family, pair<string, string> child) {
    fam_list[family].push_back(child);
  };
  void add_child(string family, vector<pair<string, string>> child_list) {
    fam_list[family].insert(fam_list[family].end(), child_list.begin(),
                            child_list.end());
  };
  void print() {
    for (const auto &f : fam_list) {
      cout << f.first << ": {";
      for (const auto &c : f.second) {
        cout << c.first << ": " << c.second << ", ";
      }
      cout << "}" << endl;
    }
  }

private:
  map<string, vector<pair<string, string>>> fam_list;
};

int main() {
  Families fam;
  fam.add_family("Lee", {make_pair("Thomas", "03/06/21"),
                         make_pair("James", "00/05/22"),
                         make_pair("Charles", "98/03/16"),
                         make_pair("Alfred", "96/05/12")});
  fam.print();
  return 0;
}