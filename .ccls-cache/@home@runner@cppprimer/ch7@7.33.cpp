#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::ostream;
using std::string;
using std::vector;

class Screen;

class Window_mgr {
public:
  Window_mgr();
  using ScreenIndex = std::vector<Screen>::size_type;
  void clear(ScreenIndex);

private:
  std::vector<Screen> screens;
};

class Screen {
  friend void Window_mgr::clear(ScreenIndex);

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

  // Size
  pos size() const;

private:
  pos cursor = 0;
  pos height = 0, width = 0;
  string contents;

  void do_display(ostream &os) const { os << contents; }
};

void Window_mgr::clear(ScreenIndex si) {
  Screen &s = screens[si];
  s.contents = string(s.height * s.width, ' ');
}

Window_mgr::Window_mgr() : screens{Screen(24, 80, ' ')} {};

/* This would be an error because the type pos is not yet within
   scope. We would have to first scope into it with the :: operator.
   Also this function is not yet declared so we can add it to the
   declaration of the class */
Screen::pos Screen::size() const { return height * width; }