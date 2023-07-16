#include "TextQuery.h"
#include <algorithm>

TextQuery::TextQuery(std::ifstream &ifs)
    : lines(std::make_shared<std::vector<std::string>>()),
      word_db(std::make_shared<std::map<std::string, std::set<size_t>>>()) {
  std::string line;
  size_t line_no = 0;
  while (std::getline(ifs, line, '\n')) {
    lines->push_back(line);
    ++line_no;
    std::istringstream iss(line);
    std::string word;
    while (iss >> word) {
      std::transform(word.begin(), word.end(), word.begin(),
                     [](unsigned char c) { return std::tolower(c); });
      if (word_db->find(word) == word_db->end()) {
        (*word_db)[word] = std::set<size_t>();
      }
      (*word_db)[word].insert(line_no);
    }
  }

  // // Debugging
  // for (auto p = word_db->begin(); p != word_db->end(); ++p) {
  //   std::cout << p->first << ": {";
  //   for (auto q = p->second.begin(); q != p->second.end(); ++q) {
  //     std::cout << *q << ", ";
  //   }
  //   std::cout << "}" << std::endl;
  // }
}

QueryResult TextQuery::query(std::string &s) {
  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return QueryResult(s, lines, word_db);
}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
  auto line_nos = (*qr.word_db)[qr.word];
  os << qr.word << " occurs " << line_nos.size() << " times\n";
  for (auto p = line_nos.cbegin(); p != line_nos.cend(); ++p) {
    os << "\t"
       << "(line " << *p << ") " << (*qr.lines)[*p - 1] << '\n';
  }
  os << std::endl;
  return os;
}