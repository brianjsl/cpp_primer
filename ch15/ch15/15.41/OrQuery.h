#pragma once
#include "BinaryQuery.h"
class OrQuery : public BinaryQuery
{
	friend Query operator| (const Query&, const Query&);

	OrQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "|") {
		//std::cout << "OrQuery(const Query& left, const Query& right)" << std::endl;
	};

	QueryResult eval(const TextQuery& text) const override;
};

inline Query operator|(const Query& lhs, const Query& rhs) {
	Query_base *q = new OrQuery(lhs, rhs);
	return q;
}

