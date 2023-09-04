#pragma once
#include <initializer_list>
#include <memory>
#include <string>

class StrVec {
public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr){};
  StrVec(std::initializer_list<std::string> il)
      : elements(nullptr), first_free(nullptr), cap(nullptr) {
    alloc_n_copy(il.begin(), il.end());
  };

  // copy constructors
  StrVec(const StrVec &);
  StrVec &operator=(const StrVec &);
  ~StrVec();

  // move semantics
  StrVec(StrVec&&);
  StrVec& operator=(StrVec&&) noexcept;

  // member functions
  void push_back(const std::string &);
  size_t size() const { return first_free - elements; }
  void reserve(size_t n);
  void resize(size_t n);
  size_t capacity() const { return cap - elements; }
  std::string *begin() const { return elements; }
  std::string *end() const { return first_free; }

private:
  static std::allocator<std::string> alloc;

  void chk_n_alloc() {
    if (size() == capacity())
      reallocate();
  }
  void free();
  std::pair<std::string *, std::string *> alloc_n_copy(const std::string *,
                                                       const std::string *);
  void reallocate();
  std::string *elements; // Pointer to the start of the vector
  std::string *first_free;
  std::string *cap;
};