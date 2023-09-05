class SmallInt {
	friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
	SmallInt(int = 0);
	operator int() const { return val; }
private:
	std::size_t val;
};

it main() {
	SmallInt s1;
	double d = s1 + 3.14; //s1 could be converted to int and then double and then added to get d. 
						  //Alternatively, 3.14 could be converted to int then smallint and then 
						  //the SmallInt::operator+(const SmallInt&, const SmallInt&) operator
						  //can be used and then convert to double.
					      //Different class conversions are used and so they are of equal rank so
						  //the expression is not legal.

	//Two ways to make it legal
	double d2 = static_cast<double>(s1) + 3.14;
	double d3 = s1 + SmallInt(3.14);
	return 0;
}