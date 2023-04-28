int main() {
  int i = 0;
  double *dp = &i; // Invalid pointer to double can not point to an int
  int *ip = i;     // Illegal, cannot assign an int to a *int
  int *p = &i;     // Legal
}
