#include <string>
#include <vector>
using namespace std;

int main() {
	"cobble" == "stone"; //operator==(const string&, const string&)

	vector<string> svec1, svec2; 

	svec1[0] == svec2[0]; //operator==(const string&, const string&)

	svec1 == svec2; //operator==(const vector<string>&, const vector<string> &)

	svec1[0] == "stone"; //operator==(const string&, const string&)
}