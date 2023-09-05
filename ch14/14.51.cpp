struct LongDouble {
	LongDouble(double d = 0.0) : i(d) {};
	operator double() {
		return i;
	};
	operator float() {
		return i;
	};

private:
	double i;
};

int main() {
	void calc(int);
	void calc(LongDouble);
	double dval;
	calc(dval); // The two viable paths are calc(int(dval)) and calc(LongDouble(dval)). The former (use of calc(int(val)) is used since
				// the arithmetic conversions have higher rank than the class type conversions.
	return 0;
}