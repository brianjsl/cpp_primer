#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Families {
public:
  void add_family(string family) { fam_list[family] = {}; }
  void add_family(string family, vector<string> child_list) {
    fam_list[family].insert(fam_list[family].end(), child_list.begin(),
                            child_list.end());
  }
  void add_child(string family, string child) {
    fam_list[family].push_back(child);
  };
  void add_child(string family, vector<string> child_list) {
    fam_list[family].insert(fam_list[family].end(), child_list.begin(),
                            child_list.end());
  };
  void print() {
    for (const auto &f : fam_list) {
      cout << f.first << ": ";
      for (const auto &c : f.second) {
        cout << c << " ";
      }
    }
    cout << endl;
  }

private:
  multimap<string, vector<string>> fam_list;
};

int main() {
  Families fam;
  fam.add_family("Lee", {"Thomas", "James", "Charles", "Alfred"});
  fam.print();
  return 0;
}