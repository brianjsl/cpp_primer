#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> processed_str(string s, char repl) {
  /*
  Creates a stack with the characters of a string s with
  the paranthesized expressions replaced with a character
  representing the replaced expression (repl).
  */
  stack<char> st;
  bool is_paren = false;
  for (const auto c : s) {
    if (c == '(') {
      is_paren = true;
      st.push(c);
    } else if (c == ')' && is_paren) {
      while (st.top() != '(') {
        st.pop();
      }
      st.pop(); // Remove the '('
      st.push(repl);
    } else {
      st.push(c);
    }
  }

  return st;
}

int main() {
  string expr = "Hello (whatver this) am a pig. (lolololl) am a cat.";
  stack<char> st = processed_str(expr, 'I');
  string new_expr;
  while (!st.empty()) {
    new_expr.push_back(st.top());
    st.pop();
  }
  string rev(new_expr.rbegin(), new_expr.rend());
  cout << rev << endl;
  return 0;
}