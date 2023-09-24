#pragma once
#include <string>
#include "TextQuery.h"
#include "Query_base.h"
#include "WordQuery.h"
#include <iostream>

class Query
{
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);

public:
	Query(const std::string& s) : q(new WordQuery(s)) {
		//std::cout << "Query(const std::string & s)" << std::endl;
	};

	QueryResult eval(const TextQuery& t) const { return q->eval(t); };
	std::string rep() const { 
		return q->rep(); 
		//std::cout << "Query::rep()" << std::endl;
	}

private:
	Query(std::shared_ptr<Query_base> query) : q(query) {}
	std::shared_ptr<Query_base> q;
};

