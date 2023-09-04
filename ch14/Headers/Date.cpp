#include "Date.h"

const std::unordered_map<int, std::string> Date::month_map = { {1, "January"}, { 2, "Feburary" }, { 3, "March" }, { 4, "April" }, { 5, "May" }, { 6, "June" },
	 { 7, "July" }, { 8, "August" }, { 9, "September" }, { 10, "October" }, { 11, "November" }, { 12, "December" } };

const std::vector<int> Date::month_days{ 31,30,31,28,31,30,31,31,30,31,30,31 };

std::istream& operator>>(std::istream& is, Date& d) {
	std::cout << "Enter Month: ";
	is >> d.month;
	std::cout << "Enter Day: ";
	is >> d.day;
	std::cout << "Enter Year: ";
	is >> d.year;
	d.daynum = d.get_daynum(d.month, d.day, d.year);
	if (!is)
		d = Date();
	return is;
};

std::ostream& operator<<(std::ostream& os, const Date& d) {
	os << d.month_map.at(d.month) << " " << d.day << d.suffix() << ", " << d.year;
	return os;
}

bool operator==(const Date& lhs, const Date& rhs) {
	return (lhs.year == rhs.year) && (lhs.month == rhs.month) && (lhs.day == rhs.day);
};

bool operator!=(const Date& lhs, const Date& rhs) {
	return !(lhs == rhs);
};

int Date::get_daynum(int m, int d, int y) const {
	int cnt = 0;

	//Add number of days in years before current year
	for (auto i = 0; i < y; ++i) {
		cnt += (is_leapyear(i)) ? 366 : 365;
	}

	//For current year add number of days in each month before current month
	for (auto i = 1; i < m; ++i) {
		cnt += month_days[i - 1];
		if (i == 4 && is_leapyear(y)) cnt += 1;
	}

	cnt += d; //Add days for the current month
	return cnt;
}

std::tuple<int, int, int> Date::get_mdy(int numdays) const {
	int yr = 0;
	int dy = 0;
	int mth = 1;

	//For each year before current add either 365 or 366 days depending on leapyear
	while (numdays > 366) {
		auto days_year_i = is_leapyear(yr) ? 366 : 365;
		numdays -= days_year_i;
		yr += 1;
	}

	//Deal with cases where 365 or 366 days left
	if (numdays == 366) {
		yr += 1;
		dy = (is_leapyear(yr)) ? 1 : 2;
	}
	else if (numdays == 365) {
		if (is_leapyear(yr)) {
			mth = 12;
			dy = 31;
		}
		else {
			dy = 1;
			yr += 1;
		}
	}
	//Deals with cases where less than 365 days left
	else {
		for (int i = 1; numdays > (month_days[i - 1] + ((i == 4 && is_leapyear(yr)) ? 1 : 0)); ++i) {
			numdays -= (month_days[i - 1] + ((i == 4 && is_leapyear(yr)) ? 1 : 0));
			mth += 1;
		}
		dy += numdays;
	}
	return { mth, dy, yr };
}

Date& Date::operator+=(int i) {
	auto cnt = get_daynum(month, day, year) + i;
	auto mdy = get_mdy(cnt);
	month = std::get<0>(mdy);
	day = std::get<1>(mdy);
	year = std::get<2>(mdy);
	return *this;
}

Date& Date::operator-=(int i) {
	*this += (-i);
	return *this;
}

std::string Date::suffix() const {
	switch (this->day) {
	case 1: case 21: case 31:
		return "st";
		break;
	case 2: case 22:
		return "nd";
		break;
	case 3:	case 23:
		return "rd";
		break;
	default:
		return "th";
		break;
	}
}

Date operator+(int i, const Date& rhs) {
	Date d = rhs;
	d += i;
	return d;
}

Date operator+(const Date& lhs, int i) {
	Date d = lhs;
	d += i;
	return d;
}

Date operator-(int i, const Date& rhs) {
	Date d = rhs;
	d -= i;
	return d;
}

Date operator-(const Date& lhs, int i) {
	Date d = lhs;
	d -= i;
	return d;
}

bool operator<(const Date&lhs, const Date&rhs) {
	return lhs.daynum < rhs.daynum;
}

bool operator<=(const Date&lhs, const Date&rhs) {
	return (lhs < rhs) || (lhs == rhs);
}

bool operator>(const Date&lhs, const Date&rhs) {
	return !(lhs <= rhs);
}

bool operator>=(const Date&lhs, const Date&rhs) {
	return !(lhs < rhs);
}

Date::Date(Date&& rhs) noexcept: month(std::move(rhs.month)), day(std::move(rhs.day)), year(std::move(rhs.year)), daynum(std::move(daynum)) {
	rhs.month = rhs.day = rhs.year = rhs.daynum = 0;
}

Date& Date::operator=(Date&& rhs) noexcept{
	if (this != &rhs) {
		month = std::move(rhs.month);
		day = std::move(rhs.day);
		year = std::move(rhs.year);
		daynum = std::move(rhs.daynum);
		rhs.month = rhs.day = rhs.year = rhs.daynum = 0;
	}
	return *this;
}

Date& Date::operator=(const std::string& s) {
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
	return *this;
}
