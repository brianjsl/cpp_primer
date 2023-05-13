#include <iostream>
#include <string>
using std::cout;
using std::ostream;
using std::string;

class Screen {
public:
  // typedefs
  using pos = string::size_type;

  // constructors
  Screen() = default;
  Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
  Screen(pos ht, pos wd, char c)
      : height(ht), width(wd), contents(ht * wd, c) {}

  // get
  char get() const { return contents[cursor]; }
  char get(pos r, pos c) const { return contents[r * width + c]; }

  // move
  Screen move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
  }

  // set
  Screen set(char val) {
    contents[cursor] = val;
    return *this;
  }

  Screen set(pos r, pos c, char val) {
    contents[r * width + c] = val;
    return *this;
  }

  // display
  Screen display(ostream &os) {
    do_display(os);
    return *this;
  }

  const Screen display(ostream &os) const {
    do_display(os);
    return *this;
  }

private:
  pos cursor = 0;
  pos height = 0, width = 0;
  string contents;

  void do_display(ostream &os) const { os << contents; }
};

int main() {
  Screen myScreen(5, 5, 'X');
  myScreen.move(4, 0).set('#').display(cout);
  cout << "\n";
  myScreen.display(cout);
  cout << "\n";
}