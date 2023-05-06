#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  const vector<string> grades = {"F", "D", "C", "B", "A"};
  int grade = 73;
  string letterGrade;
  if (grade < 60) {
    letterGrade = grades[0];
  } else {
    letterGrade = grades[(grade - 50) / 10];
    if (grade % 10 > 7)
      letterGrade += "+";
    else if (grade % 10 < 3)
      letterGrade += "-";
  }
  cout << letterGrade << endl;
  return 0;
}