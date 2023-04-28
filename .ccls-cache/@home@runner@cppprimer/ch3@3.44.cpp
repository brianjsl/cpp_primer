#include <iostream>
using namespace std;
typedef size_t st;
typedef int int_arr[4];

int main() {
  constexpr st rowCnt = 3, colCnt = 4;
  int ia[rowCnt][colCnt];
  for (st row = 0; row != rowCnt; ++row) {
    for (st col = 0; col != colCnt; ++col) {
      ia[row][col] = row * colCnt + col;
    }
  }

  for (int_arr &row : ia) {
    for (int &col : row) {
      cout << col << " ";
    }
    cout << endl;
  }

  for (st i = 0; i != rowCnt; ++i) {
    for (st j = 0; j != colCnt; ++j) {
      cout << ia[i][j] << " ";
    }
    cout << endl;
  }

  for (int_arr *row = begin(ia); row != end(ia); ++row) {
    for (int *col = begin(*row); col != end(*row); ++col) {
      cout << *col << " ";
    }
    cout << endl;
  }
  return 0;
}