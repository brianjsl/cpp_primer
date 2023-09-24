#include <vector>
#include "Quote.h"
#include "Bulk_quote.h"
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

void main1528() {
	vector<Quote> vec;
	vec.push_back(Bulk_quote("0-201-54848-8", 50, 6, .25));
	vec.push_back(Bulk_quote("0-201-54848-9", 30, 8, .15));
	vec.push_back(Bulk_quote("0-201-54848-0", 25, 7, .45));
	vec.push_back(Bulk_quote("0-201-54848-X", 18, 10, .05));

	//will all not produce the discount since we "slice down" to just a regular Quote object
	cout << vec[0].net_price(10) << endl; //50*10=500
	cout << vec[1].net_price(10) << endl; //30*10=300
	cout << vec[2].net_price(10) << endl; //25*10=250
	cout << vec[3].net_price(10) << endl; //18*10=180
}