#pragma once

#include "StrBlob.h"
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class StrBlobPtr {
public:
  StrBlobPtr() : curr(0){};
  StrBlobPtr(const StrBlob &a, std::vector<std::string>::size_type sz = 0)
      : wptr(a.data), curr(sz){};
  std::string &deref() const;
  StrBlobPtr &incr();

private:
  std::shared_ptr<std::vector<std::string>> check(std::size_t,
                                                  const std::string &) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
};