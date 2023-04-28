int main() {
  int ival = 1.01;   // Valid, truncates to an int (ie. ival = 1)
  int &rval1 = 1.01; // Invalid, cant make a reference to a literal
  int &rval2 = ival; // Valid, rval2 is bound to ival
  int &rval3;        //Invalid, references must be initialized.\
}