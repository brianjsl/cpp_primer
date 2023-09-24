#include <vector>
#include "Quote.h"
#include "Bulk_quote.h"
#include <iostream>
#include <memory>
using std::vector;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;

void main1529() {
	vector<shared_ptr<Quote>> vec;
	vec.push_back(make_shared<Bulk_quote>("0-201-54848-8", 50, 6, .25));
	vec.push_back(make_shared<Bulk_quote>("0-201-54848-9", 30, 8, .15));
	vec.push_back(make_shared<Bulk_quote>("0-201-54848-0", 25, 7, .45));
	vec.push_back(make_shared<Bulk_quote>("0-201-54848-X", 18, 10, .05));

	//will all not produce the discount since we "slice down" to just a regular Quote object
	cout << vec[0]->net_price(10) << endl; //50*10*(1-0.25)=375
	cout << vec[1]->net_price(10) << endl; //30*10*(1-0.15)=255
	cout << vec[2]->net_price(10) << endl; //25*10*(1-0.45)=137.5
	cout << vec[3]->net_price(10) << endl; //18*10*(1-0.05)=171
}