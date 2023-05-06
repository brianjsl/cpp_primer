#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  const vector<string> grades = {"F", "D", "C", "B", "A"};
  int grade = 73;
  string letterGrade = (grade < 60) ? grades[0] : grades[(grade - 50) / 10];
  letterGrade += (grade % 10 < 3) ? "-" : (grade % 10 > 7) ? "+" : "";
  cout << letterGrade << endl;
  return 0;
}