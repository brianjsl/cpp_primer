#pragma once

#ifndef STRING_H
#include <string>
#define STRING_H
#endif

#ifndef INITIALIZER_LIST_H
#include <initializer_list>
#define INITIALIZER_LIST_H
#endif

class StrBlob {
public:
  typedef std::vector<std::string>::size_type size_type;
  StrBlob();
  StrBlob(std::initializer_list<std::string> il);
  size_type size() const { return da}
private:

}

