int main() {
  const int i = 42;  // i is a const int
  auto j = i;        // j is a int
  const auto &k = i; // k is a reference to a const int
  auto *p = &i;      // p is a pointer to a const int
  const auto j2 = i,
             &k2 = i; // j2 is a const int, k2 is a reference to a const int

  return 0;
}