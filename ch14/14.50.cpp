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
	LongDouble ldObj; //object defined
	//int ex1 = ldObj; //Longdouble could be converted to double then int or to float then int. The conversion is ambiguous.
	float ex2 = ldObj; //Legal since conversion to float has lower rank.
	return 0;
}
