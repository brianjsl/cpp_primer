#include "StrBlob.h"
#include "StrBlobPtr.h"

void StrBlob::check(size_type i, const std::string &msg) const {
  if (i >= data->size())
    throw std::out_of_range(msg);
}

void StrBlob::pop_back() {
  check(0, "pop_back on emptyStrBlob");
  this->pop_back();
}

std::string &StrBlob::front() {
  check(0, "front on emptyStrBlob");
  return this->front();
}

std::string &StrBlob::back() {
  check(0, "back on emptyStrBlob");
  return this->back();
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); };

StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, this->size()); }