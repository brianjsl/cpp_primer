int main() {
  int i = 0, &r1 = i;
  double d = 0, &r2 = d;

  r2 = 3.14159; // Valid,d is now bound to 3.14159
  r2 = r1;      // Valid, d is now bound to 0
  i = r2;       // i is now bound to 0
  r1 = d;       // Valid, i is now bound to 0
}