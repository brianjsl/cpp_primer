#include <iostream>
using namespace std;

int main() {
  constexpr size_t rowCnt = 3, colCnt = 4;
  int ia[rowCnt][colCnt];
  for (auto row = 0; row != rowCnt; ++row) {
    for (auto col = 0; col != colCnt; ++col) {
      ia[row][col] = row * colCnt + col;
    }
  }

  for (auto &row : ia) {
    for (auto &col : row) {
      cout << col << " ";
    }
    cout << endl;
  }

  for (auto i = 0; i != rowCnt; ++i) {
    for (auto j = 0; j != colCnt; ++j) {
      cout << ia[i][j] << " ";
    }
    cout << endl;
  }

  for (auto *row = begin(ia); row != end(ia); ++row) {
    for (auto *col = begin(*row); col != end(*row); ++col) {
      cout << *col << " ";
    }
    cout << endl;
  }
  return 0;
}