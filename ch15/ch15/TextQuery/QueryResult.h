#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

class QueryResult {
    friend std::ostream& operator<<(std::ostream&, const QueryResult&);
public:

    using line_no = std::vector<std::string>::size_type;

    QueryResult(const std::string& s,
        std::shared_ptr<std::set<line_no>> p,
        std::shared_ptr<std::vector<std::string>> f)
        : word(s), lines(p), file(f) {};

    std::set<size_t>::iterator begin() const { return lines ->begin(); }

    std::set<size_t>::iterator end() const { return lines->end(); }

    std::shared_ptr<std::vector<std::string>> get_file() const { return file; }

private:
    const std::string word;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

