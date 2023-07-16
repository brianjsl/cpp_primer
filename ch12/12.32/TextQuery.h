#pragma once

#include "StrBlobPtr.h"
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class QueryResult {
public:
  friend std::ostream &print(std::ostream &, const QueryResult &);

  QueryResult(const std::string &s, StrBlob &ln,
              std::shared_ptr<std::set<size_t>> wl)
      : word(s), lines(ln), which_lines(wl){};

private:
  const std::string &word;
  const StrBlob lines;
  std::shared_ptr<std::set<size_t>> which_lines;
};

class TextQuery {
public:
  using size_t = std::vector<std::string>::size_type;
  TextQuery(std::ifstream &);
  QueryResult query(std::string &s);

private:
  StrBlob lines;
  std::map<std::string, std::shared_ptr<std::set<size_t>>> word_db;
};

std::ostream &print(std::ostream &, const QueryResult &);