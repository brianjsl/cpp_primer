#include "TextQuery.h"
#include "Query.h"
#include "AndQuery.h"
#include "OrQuery.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
	ifstream ifs("story.in");
	TextQuery text(ifs);
	Query q = Query("fiery") & Query("bird") | Query("wind");
	auto res = q.eval(text);
	cout << res;
	return 0;
}