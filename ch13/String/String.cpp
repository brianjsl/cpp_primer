#include "String.h"

void String::free() {
  std::for_each(elements, first_free,
                [](char s) -> void { alloc.destroy(&s); });
  alloc.deallocate(elements, cap - elements);
}

std::pair<char *, char *> String::alloc_n_copy(const char *b, const char *e) {
  auto data = alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
}

String::String(const String &s) {
  auto newdata = alloc_n_copy(s.begin(), s.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
  std::cout << "String(const String &s)" << std::endl;
}

String::~String() { free(); }

String &String::operator=(const String &rhs) {
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  std::cout << "operator=(const String &rhs)" << std::endl;
  return *this;
}

String::String(const char *s)
    : elements(nullptr), first_free(nullptr), cap(nullptr) {
    std::cout << "String(const char *s)" << std::endl;
  auto begin = s;
  while (*s != '\0') {
    ++s;
  }
  auto newdata = alloc_n_copy(begin, s);
  elements = newdata.first;
  first_free = cap = newdata.second;
};

void String::reserve(size_t n) {
  if (n > capacity()) {
    auto newdata = alloc.allocate(n);

    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
      alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + n;
  }
}

String& String::operator+(const String &rhs) {
  reserve(size() + rhs.size());
  auto dest = first_free;
  auto newitem = rhs.begin();
  while (dest != cap) {
    alloc.construct(dest++, *newitem++);
  }
  first_free += rhs.size();
  cap = first_free;
  return *this;
};

void String::reallocate() {
  auto newcapacity = size() ? 2 * size() : 1;
  auto newdata = alloc.allocate(newcapacity);

  auto dest = newdata;
  auto elem = elements;
  for (size_t i = 0; i != size(); ++i)
    alloc.construct(dest++, std::move(*elem++));
  free();
  elements = newdata;
  first_free = dest;
  cap = elements + newcapacity;
}

String::String(String&& s) noexcept: elements(s.elements), first_free(s.first_free), cap(s.cap) {
    std::cout << "String(String &&s) noexcept" << std::endl;
    s.elements = s.first_free = s.cap = nullptr;
}

String& String::operator=(String&&rhs) noexcept {
    std::cout << "String& operator=(String &&s) noexcept" << std::endl;
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

std::allocator<char> String::alloc;