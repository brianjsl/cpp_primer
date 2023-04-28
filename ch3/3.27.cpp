#include <vector>

using namespace std;

int txt_size() { return 0; }
int main() {
  unsigned buf_size = 1024;
  int ia[buf_size];            // Illegal since buf_size is not a constexpr
  int ib[4 * 7 - 14];          // Legal expression is a constexpr
  int ic[txt_size()];          // Illegal, txt_size() is not a constexpr
  char st[11] = "fundamental"; // Illegal, fundamental has 12 chars including \0
}