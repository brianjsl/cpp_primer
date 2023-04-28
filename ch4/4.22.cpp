#include <iostream>
#include <string>
using namespace std;

int main() {
  int grade = 73;
  string finalgrade = (grade >= 90)   ? "High pass"
                      : (grade >= 75) ? "Pass"
                      : (grade >= 60) ? "Low pass"
                                      : "Fail";
  cout << "Grade: " << finalgrade << endl;

  if (grade >= 90) {
    finalgrade = "High pass";
  } else if (grade >= 75) {
    finalgrade = "Pass";
  } else if (grade >= 60) {
    finalgrade = "Low pass";
  } else {
    finalgrade = "Fail";
  } // Cleaner
  return 0;
}