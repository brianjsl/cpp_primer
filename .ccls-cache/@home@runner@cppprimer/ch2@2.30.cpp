int main() {
  const int v2 = 0;                              // top level
  int v1 = v2;                                   // none
  int *p1 = &v1, &r1 = v1;                       // none, none
  const int *p2 = &v2, *const p3 = &i, &r2 = v2; // low level, both, low level
  return 0;
}