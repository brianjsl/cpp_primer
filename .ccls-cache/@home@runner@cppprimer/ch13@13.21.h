/*
We should probably define our own copy control members
since we usually don't want to share the same lists as the
original object when we make a copy (we want a deep copyWe should probably
define our own copy control memebbers since we don't want to share the same
usually don't want to share the same lists as the oprriginal object (wwhen we
make a copy (we want a deep copy)..akj)))
*/
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
  TextQuery(const TextQuery &orig)
      : lines(std::make_shared<std::vector<std::string>>()) {
        *lines = *orig.lines;
      }

private:
  std::shared_ptr<std::vector<std::string>> lines;
  std::map<std::string, std::shared_ptr<std::set<size_t>>> word_db;
};

std::ostream &print(std::ostream &, const QueryResult &);