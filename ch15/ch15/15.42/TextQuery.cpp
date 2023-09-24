#include "TextQuery.h"
#include <algorithm>

TextQuery::TextQuery(std::ifstream& ifs) : file(new std::vector<std::string>)
{
    std::string text;
    while (std::getline(ifs, text)) {
        file ->push_back(text);
        auto n = file->size() - 1;
        std::istringstream line(text);
        std::string word;
        while (line >> word) {
            std::transform(word.begin(), word.end(), word.begin(),
                [](unsigned char c) { return std::tolower(c); });
            auto& lines = wm[word];
            if (!lines) {
                lines.reset(new std::set<line_no>);
            }
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(std::string s) const {
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return std::tolower(c); });
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    auto loc = wm.find(s);
    if (loc == wm.end())
        return QueryResult(s, nodata, file);
    else
        return QueryResult(s, loc -> second, file);
}
