#pragma once
#include "BinaryQuery.h"

class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "&") {
		//std::cout << "AndQuery(const Query& left, const Query& right)" << std::endl;
	};
	QueryResult eval(const TextQuery&) const override;
};

inline Query operator&(const Query& lhs, const Query& rhs) {
	Query_base *q =  new AndQuery(lhs, rhs);
	return q;
}

