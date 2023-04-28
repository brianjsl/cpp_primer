int main() {
  int i = -1, &r = 0;  // Illegal since a reference must be to that of an object
  int *const p2 = &i2; // Legal
  const int i = -1,
            &r = 0; // Legal, const references can be assigned to literals
  const int *const p3 = &i2; // Legal
  const int *p1 = &i2;       // Legal
  const int &const r2; // Illegal since we can not have a "const reference" and
                       // not initialized
  const int i2 = i, &r = i // Legal
}