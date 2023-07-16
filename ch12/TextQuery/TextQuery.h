#pragma once

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

  QueryResult(const std::string &s,
              std::shared_ptr<std::vector<std::string>> ln,
              std::shared_ptr<std::set<size_t>> wl)
      : word(s), lines(ln), which_lines(wl){};

  std::set<size_t>::iterator begin() const { return which_lines->begin(); }

  std::set<size_t>::iterator end() const { return which_lines->end(); }

  std::shared_ptr<std::vector<std::string>> get_file() const { return lines; }

private:
  const std::string &word;
  std::shared_ptr<std::vector<std::string>> lines;
  std::shared_ptr<std::set<size_t>> which_lines;
};

class TextQuery {
public:
  using size_t = std::vector<std::string>::size_type;
  TextQuery(std::ifstream &);
  QueryResult query(std::string &s);

private:
  std::shared_ptr<std::vector<std::string>> lines;
  std::map<std::string, std::shared_ptr<std::set<size_t>>> word_db;
};

std::ostream &print(std::ostream &, const QueryResult &);