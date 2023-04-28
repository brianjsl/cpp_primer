int main() {
  i = ic;   // legal since assigned value can be a const
  p1 = p3;  // Illegal. Top level const is ignored, but the lower level const is
            // not and lower level const cannot be converted to noncost
  p1 = &ic; // Illegal. pointer to an int cannot point to a const int
  p3 = &ic; // Illegal since cannot assign to a const.
  p2 = p1;  // Illegal since cannot assign to a const.
  ic = *p3; // Illegal since cannot assign to a const.
}