#pragma once
#include "Query.h"
#include "Query_base.h"

class NotQuery : public Query_base
{
	friend Query operator~(const Query&);
	friend class Query;

	NotQuery(const Query& q) : query(q) {
		//std::cout << "NotQuery(const Query &q)" << std::endl;
	}

	std::string rep() const { 
		//std::cout << "NotQuery::rep()" << std::endl;
		return "~(" + query.rep() + ")"; 
	};
	QueryResult eval(const TextQuery&) const;
	Query query;
};

inline Query operator~(const Query& operand) {
	Query_base* q = new NotQuery(operand);
	return q;
}


