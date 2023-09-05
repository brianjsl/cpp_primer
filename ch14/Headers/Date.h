#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <utility>
#include <unordered_map>
#include <tuple>

class Date {
	friend std::istream& operator>>(std::istream&, Date&);
	friend std::ostream& operator<<(std::ostream&, const Date&);
	friend bool operator==(const Date&, const Date&);
	friend bool operator!=(const Date&, const Date&);
	friend bool operator<(const Date&, const Date&);
	friend bool operator<=(const Date&, const Date&);
	friend bool operator>(const Date&, const Date&);
	friend bool operator>=(const Date&, const Date&);
	friend Date operator+(int, const Date&); //could define arithmetic but difficult
	friend Date operator+(const Date&, int);
	friend Date operator-(int, const Date&);
	friend Date operator-(const Date&, int);

public:

	//Default Constructors
	explicit Date(int month = 1, int day = 1, int year = 2023)  : year(year), month(month), day(day) {
		// Set default to new years day of the current year
		if (!check_mth())
			throw std::invalid_argument("Invalid Month");
		if (!check_day())
			throw std::invalid_argument("Invalid Day");
		daynum = get_daynum(month, day, year);
	}

	explicit Date(std::istream& is): year(2023), month(1), day(1), daynum(0) { is >> *this; }


	//Gets date from a string (in the formate m/d/y)
	Date(const std::string& s) : year(2023), month(1), day(1) {
		try {
			size_t start = 0;
			auto end = s.find("/", start);
			month = std::stoi(s.substr(start, end - start));
			start = end + 1;
			end = s.find("/", start);
			day = std::stoi(s.substr(start, end - start));
			start = end + 1;
			end = s.length();
			year = std::stoi(s.substr(start, end - start));
			daynum = get_daynum(month, day, year);
		}
		catch (...) {
			std::cout << "Invalid Date!" << std::endl;
		}
	}

	//Gets date from number of days since 1/1 of Year 0.
	explicit Date(const int daynum): daynum(daynum) {
		auto mdy = get_mdy(daynum);
		month = std::get<0>(mdy);
		day = std::get<1>(mdy);
		year = std::get<2>(mdy);
	}

	//Copy constructors
	Date(const Date& d) = default;
	Date& operator=(const Date&) = default;
	~Date() = default;

	//Move constructors
	Date(Date&&) noexcept;
	Date& operator=(Date&&) noexcept;

	//Overloaded operators
	Date& operator+=(int);
	Date& operator-=(int);
	Date& operator=(const std::string&);


	int get_daynum_curr() const {
		return get_daynum(month, day, year);
	}

	explicit operator bool() const {
		return check_mth() && check_day() && (year >= 0) && valid_comb(day, month, year);
	}


private:

	int month;
	int day;
	int year;

	//represents the number of days since 1/1 (New Year's Day) of year 0
	int daynum;

	const static std::unordered_map<int, std::string> month_map; //map from month (int) to a string representing name of month
	const static std::vector<int> month_days; //number of days in each month (28 default for August)

	//get numdays from month, day, year
	int get_daynum(int m, int d, int y) const;

	//get month,day,year from numdays
	std::tuple<int, int, int> get_mdy(int numdays) const;


	bool check_mth() const {
		return (1 <= month && month <= 12); //checks for valid month
	}

	bool check_day() const {
		return (1 <= day && day <= 31) && valid_comb(day, month, year); //checks for valid day
	}

	bool is_leapyear(int yr) const {
		return (((yr % 4 == 0) && (yr % 100 != 0)) || yr % 400 == 0);
	}

	bool valid_comb(int d, int m, int y) const {
		//checks for combination of month and day
		if (m == 4) {
			return (d <= 28) || (d == 29 && is_leapyear(y));
		}
		if (d == 31) {
			return (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12);
		}
		return true;
	}

	//Function that returns string suffix to add to day
	std::string suffix() const;
};

