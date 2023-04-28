int main() {
  int i, *const cp;      // Integer, contant pointer to int ILLEGAL since not
                         // initialized
  int *p1, *const p2;    // pointer to int, constant pointer to int ILLEGAl ^
  const int ic, &r = ic; // const int, reference to a const int ILLEGAL ^
  const int *const p3;   // constant pointer to a const int ILLEGAL ^
  const int *p; // pointer to a const int LEGAL since not high level const
}