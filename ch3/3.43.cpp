#include <iostream>
using namespace std;

int main() {
  constexpr size_t rowCnt = 3, colCnt = 4;
  int ia[rowCnt][colCnt];
  for (size_t row = 0; row != rowCnt; ++row) {
    for (size_t col = 0; col != colCnt; ++col) {
      ia[row][col] = row * colCnt + col;
    }
  }

  for (int(&row)[colCnt] : ia) {
    for (int &col : row) {
      cout << col << " ";
    }
    cout << endl;
  }

  for (size_t i = 0; i != rowCnt; ++i) {
    for (size_t j = 0; j != colCnt; ++j) {
      cout << ia[i][j] << " ";
    }
    cout << endl;
  }

  for (int(*row)[4] = begin(ia); row != end(ia); ++row) {
    for (int *col = begin(*row); col != end(*row); ++col) {
      cout << *col << " ";
    }
    cout << endl;
  }
  return 0;
}