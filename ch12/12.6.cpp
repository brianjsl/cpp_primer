#include <iostream>
#include <new>
#include <vector>
using namespace std;

vector<int> *retVec(initializer_list<int> il) { return new vector<int>(il); }

void addElems(vector<int> &vec) {
  int i;
  while (cin >> i) {
    vec.push_back(i);
  }
}

void print(const vector<int> &vec) {
  for (const auto &v : vec) {
    cout << v << " ";
  }
  cout << endl;
}

int main() {
  auto v = retVec({});
  addElems(*v);
  print(*v);
  delete v;
}