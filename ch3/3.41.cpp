#include <vector>
using namespace std;

int main() {
  int arr[] = {1, 4, 2, 3, 9};
  vector<int> v(begin(arr), end(arr));
  return 0;
}