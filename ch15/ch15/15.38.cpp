#include "BinaryQuery.h"
#include "Query.h"
#include "AndQuery.h"
#include "OrQuery.h"
#include "WordQuery.h"

int main() {
	BinaryQuery a = Query("fiery") & Query("bird"); //Illegal, BinaryQuery is an abstract base class
	AndQuery b = Query("fiery") & Query("bird"); //Illegal, no constructor that creates an AndQuery from a Query class and constructors nonpublic
	OrQuery c = Query("fiery") & Query("bird"); //Same as above
	return 0;
}