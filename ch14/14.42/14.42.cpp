#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
using std::greater;
using std::not_equal_to;
using std::count_if;
using std::cout;
using std::endl;
using std::bind;
using std::string;
using std::transform;
using std::multiplies;
using std::find_if;
using namespace std::placeholders;

int main() {
	//a
	vector<int> vec = {1025, 1027, 85, 999, 2049};
	cout << count_if(vec.begin(), vec.end(), bind(greater<int>(), _1, 1024)) << endl;;

	//b
	vector<string> vec2 = { "pooh", "pooh", "poo", "thing" };
	cout << *find_if(vec2.begin(), vec2.end(), bind(not_equal_to<string>(), _1, "pooh")) << endl;

	//c
	vector<int> vec3 = { 1,2,3,4,5,6 };
	transform(vec3.begin(), vec3.end(), vec3.begin(), bind(multiplies<int>(), _1, 2));
	for (const auto v : vec3) {
		cout << v << " ";
	}
	return 0;
}