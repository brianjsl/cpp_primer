int main() {
  const int v2 = 0;                              // top level
  int v1 = v2;                                   // none
  int *p1 = &v1, &r1 = v1;                       // none, none
  const int *p2 = &v2, *const p3 = &i, &r2 = v2; // low level, both, low level

  r1 = v2; // legal: r1 becomes an alias for v2
  p1 = p2; // illegal since p2 has lower level const
  p2 = p1; // legal since p1 lower level int converted to const int
  p1 = p3; // illegal since though top level const ignored lower level const
           // exists
  p2 = p3; // legal since top level const ignored.

  return 0;
}