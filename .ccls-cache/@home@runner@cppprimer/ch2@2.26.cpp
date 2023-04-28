int main() {
  const int buf;      // Illegal, consts must be initialized
  int cnt = 0;        // Legal
  const int sz = cnt; // Legal
  ++cnt;              // Legal
  ++sz;               // Illegal, operations cant modify const 
}