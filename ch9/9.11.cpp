#include <vector>
using namespace std;

int main() {
  vector<int> vec1;                // Default initialized, contains no values
  vector<int> vec2 = {1, 2, 3, 4}; // Copy initialized, has values 1,2,3,4
  vector<int> vec3(vec2);          // Creates a copy of vec2, has values 1,2,3,4
  vector<int> vec4(10, 3);         // Creates a vector with 10 values of all 3
  vector<int> vec5(
      8); // Creates a vector with 8 default-initialized values (ie. 8 0s)
  vector<int> vec6(vec3.begin(),
                   vec3.end()); // Creates a vector with values 1,2,3,4
}