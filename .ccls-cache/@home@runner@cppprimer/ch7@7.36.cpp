// Error: rem is defined first so it is defined in
// terms of an uninitalized variable. namely base

// struct X {
//   X(int i, int j) : base(i), rem(base % j) {}
//   int rem, base;
// }

// Corrected by switching the order of base and rem
struct X {
  X(int i, int j) : base(i), rem(base % j) {}
  int base, rem;
}