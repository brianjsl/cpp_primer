#include "TextQuery.h"
#include <algorithm>

TextQuery::TextQuery(std::ifstream &ifs)
    : lines(std::make_shared<std::vector<std::string>>()),
      word_db(std::map<std::string, std::shared_ptr<std::set<size_t>>>()) {
  std::string line;
  while (std::getline(ifs, line, '\n')) {
    lines->push_back(line);
    size_t line_no = lines->size() - 1;
    std::istringstream iss(line);
    std::string word;
    while (iss >> word) {
      std::transform(word.begin(), word.end(), word.begin(),
                     [](unsigned char c) { return std::tolower(c); });
      auto &word_set = word_db[word];
      if (!word_set) {
        word_set.reset(new std::set<size_t>);
      }
      word_set->insert(line_no);
    }
  }
}

QueryResult TextQuery::query(std::string &s) {
  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return QueryResult(s, lines, word_db[s]);
}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
  os << qr.word << " occurs " << qr.which_lines->size() << " times\n";
  for (auto p = qr.which_lines->cbegin(); p != qr.which_lines->cend(); ++p) {
    os << "\t"
       << "(line " << *p + 1 << ") " << (*qr.lines)[*p] << '\n';
  }
  os << std::endl;
  return os;
}