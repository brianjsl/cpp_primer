#include <algorithm>
#include <iostream>
#include <memory>

class String {
public:
  // default constructors
  String() : elements(nullptr), first_free(nullptr), cap(nullptr){};
  String(const char *s);

  // copy constructors
  String(const String &);
  String &operator=(const String &);
  ~String();

  //move semantics
  String(String&&) noexcept;
  String& operator=(String&&) noexcept;

  // member functions
  size_t size() const { return first_free - elements; }
  size_t length() const { return first_free - elements; }

  String &operator+(const String &);
  char operator[](size_t n) { return *(begin() + n); };

  char *begin() const { return elements; };
  char *end() const { return first_free; };

  void print() const {
    for (auto idx = elements; idx != first_free; ++idx) {
      std::cout << *idx;
    }
  }

private:
  static std::allocator<char> alloc;

  size_t capacity() const { return cap - elements; }
  void reserve(size_t n);

  void chk_n_alloc() {
    if (size() == capacity())
      reallocate();
  }
  void free();
  std::pair<char *, char *> alloc_n_copy(const char *, const char *);
  void reallocate();

  char *elements;   // Pointer to the start of the string
  char *first_free; // Pointer to the first free element of the string
  char *cap;        // Pointer to one past the last allcated element
};