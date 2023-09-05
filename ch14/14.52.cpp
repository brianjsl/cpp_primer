class SmallInt {

friend SmallInt operator+(const SmallInt&, const SmallInt&);

public:
	SmallInt(int = 0);
	operator int() const { return val;  }
private:
	std::size_t val;
};

struct LongDouble {
	LongDouble(double d = 0.0);
	LongDouble operator+(const SmallInt&);

	operator double();
	operator float();
};

int main() {
	LongDouble operator+(LongDouble&, double);
	SmallInt si;
	LongDouble ld;

	/* 
	Candidate: operator+(LongDouble&, double) and LongDouble operator+(const SmallInt&) (only ways to get a LongDouble), SmallInt operator+(const SmallInt&, const SmallInt&),
	and the arithmetic + operator 

	Viable: onlyt he arithemtic + operators are viable

	Conversions: no valid operator (since int or double or float could be used!)

	*/
	ld = si + ld; 

	/*
	Candidate: operator+(LongDouble&, double) and LongDouble operator+(const SmallInt&) (only ways to get a LongDouble), SmallInt operator+(const SmallInt&, const SmallInt&),
	and the arithmetic + operator

	Viable: The second one requires no conversion other than SmallInt to const SmallInt& , while the first one requires a class conversion to int then double.
	The last one requires a conversion of both to double and then a conversion from double to LongDouble. The third one requires two class conversions to SmallInt.
	So only the second one is viable.

	Thus, only Longdouble::operator+ (const SmallInt&) is the only viable.

	Conversions: (SmallInt to const SmallInt&)
	*/
	ld = ld + si;
}