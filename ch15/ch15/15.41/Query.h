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
	Query(const std::string& s) : q(new WordQuery(s)), ref_count(new size_t(1)) {
		//std::cout << "Query(const std::string & s)" << std::endl;
	};

	QueryResult eval(const TextQuery& t) const { return q->eval(t); };

	std::string rep() const { 
		return q->rep(); 
		//std::cout << "Query::rep()" << std::endl;
	}

	//copy control
	Query(const Query& orig) : q(orig.q), ref_count(orig.ref_count) {
		++* ref_count;
	};

	Query& operator=(const Query&rhs) {
		if (this != &rhs) {
			if (-- * ref_count == 0) {
				delete q;
				delete ref_count;
			}
			q = rhs.q;
			ref_count = rhs.ref_count;
			++*ref_count;
		}
		return *this;
	}

	~Query() {
		if (-- * ref_count == 0) {
			delete q;
			delete ref_count;
		}
	}

private:
	Query(Query_base *query) : q(query), ref_count(new size_t(1)) {}
	Query_base *q;
	std::size_t *ref_count;
};

