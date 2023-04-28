int main() {
  int *ip, i,
      &r = i; // pointer to an int, int, reference to an int; all uninitialized
  int i, *ip = 0; //int (uninitialized), pointer to int (nullptr)\
  int *ip, ip2; //Pointer to int and int (uninitialized)
}