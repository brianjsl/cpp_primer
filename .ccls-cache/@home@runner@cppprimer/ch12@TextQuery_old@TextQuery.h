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
              std::shared_ptr<std::map<std::string, std::set<size_t>>> wdb)
      : word(s), lines(ln), word_db(wdb){};

private:
  const std::string &word;
  std::shared_ptr<std::vector<std::string>> lines;
  std::shared_ptr<std::map<std::string, std::set<size_t>>> word_db;
};

class TextQuery {
public:
  TextQuery(std::ifstream &);
  QueryResult query(std::string &s);

private:
  std::shared_ptr<std::vector<std::string>> lines;
  std::shared_ptr<std::map<std::string, std::set<size_t>>> word_db;
};

std::ostream &print(std::ostream &, const QueryResult &);