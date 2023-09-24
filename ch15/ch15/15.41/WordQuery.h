#pragma once
#include "Query_base.h" 
#include "TextQuery.h"

class WordQuery: public Query_base {
	friend class Query;
	WordQuery(const std::string& s) : query_word(s) {
		//std::cout << "WordQuery(const std::string &s)" << std::endl;
	};

	QueryResult eval(const TextQuery& t) const override{
		return t.query(query_word);
	}

	std::string rep() const { 
		//std::cout << "WordQuery::rep()" << std::endl;
		return query_word;  
	}
	std::string query_word; //word to search
};

