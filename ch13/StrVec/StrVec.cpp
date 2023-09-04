#include "StrVec.h"
#include <algorithm>

void StrVec::push_back(const std::string &s) {
  chk_n_alloc();
  alloc.construct(first_free++, s);
}

std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
  auto data = alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free() {
  // old version
  // if (elements) {
  //   for (auto p = first_free; p != elements;)
  //     alloc.destroy(--p);
  //   alloc.deallocate(elements, cap - elements);
  // }
  // With lamdba
  std::for_each(elements, first_free,
                [](std::string s) -> void { alloc.destroy(&s); });
  alloc.deallocate(elements, cap - elements);
}

StrVec::StrVec(const StrVec &s) {
  auto newdata = alloc_n_copy(s.begin(), s.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs) {
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

void StrVec::reallocate() {
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

void StrVec::reserve(size_t n) {
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

void StrVec::resize(size_t n) {
  if (n < size()) {
    auto rem = size() - n;
    while (rem > 0) {
      alloc.destroy(--first_free);
      --rem;
    }
  } else if (n > size()) {
    reserve(n);
    auto rem = n - size();
    while (rem > 0) {
      alloc.construct(first_free++, "");
    }
  }
}

StrVec::StrVec(StrVec&& s) noexcept: elements(s.elements), first_free(s.first_free), cap(s.cap) {
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec&& rhs) {
    if (this != &rhs) {
        free(); //existing elements need to be destroyed
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}
