
#include "date.h"

Date::Date()
{
	// current date/time based on current system
	time_t now = time(0);
	tm* ltm = localtime(&now);
	_year = 1900 + ltm->tm_year;
	_month = 1 + ltm->tm_mon;
	_day = ltm->tm_mday;
}

Date::Date(int m, int y)
{
	_day = 0;
	_month = m;
	_year = y;
}

int Date::getDay() const
{
	return _day;
}

int Date::getMonth() const
{
	return _month;
}

int Date::getYear() const
{
	return _year;
}

ostream& operator<<(ostream& os, const Date& date)
{
	os << date._day << "/" << date._month << "/" << date._year << endl;
	return os;
}
